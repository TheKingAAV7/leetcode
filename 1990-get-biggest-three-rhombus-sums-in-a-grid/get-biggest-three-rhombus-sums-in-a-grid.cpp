class Solution {
public:

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<int>ro={1,1,-1,-1};
      vector<int>col={1,-1,-1,1};
      set<int,greater<int>>st;

      // recursive walker: we move first, then add the new cell to the sum
      auto f=[&](auto &&self,int i, int j,int curlen, int &len, int &sm,bool &reached, int &cnt,int &si,int &sj,int mod)->void{
        // if we've already visited required number of perimeter cells, check if we're back at start
        if(cnt == 4 * len){
            if(i==si && j==sj) reached = true;
            return;
        }

        // compute next cell to move to
        int ni = i + ro[mod];
        int nj = j + col[mod];

        // bounds check for the next cell
        if(ni < 0 || ni >= n || nj < 0 || nj >= m) return;

        // move there and add its value
        sm += grid[ni][nj];
        cnt++;

        // if that was the last step of the current side, rotate and reset curlen
        if(curlen == 1){
            int nextmod = (mod + 1) % 4;
            // start full length on next side
            self(self, ni, nj, len, len, sm, reached, cnt, si, sj, nextmod);
        } else {
            // continue along the same side
            self(self, ni, nj, curlen - 1, len, sm, reached, cnt, si, sj, mod);
        }
        return;
      };

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            st.insert(grid[i][j]);
            // compute maximum valid side length (space available to right, left and down)
            int maxright = m - j - 1;
            int maxlef  = j;
            int maxdown = n - i - 1;
            int maxhor = min({maxright, maxlef, maxdown});
            
            // len = side length; start from 1 (one-step side)
            for(int len=1; len<=maxhor; len++){
                int sm=0;
                bool reached=false;
                int cnt=0;
                // IMPORTANT: we call f with current position (i,j). The walker will move first.
                f(f, i, j, len, len, sm, reached, cnt, i, j, 0);
                if(reached) st.insert(sm);
            }
        }
      }
      vector<int>ans;
      int k=3;
      while(!st.empty() and k--){
        ans.push_back(*st.begin());
        st.erase(st.begin());
      }
      return ans;

    }
};