class Solution {
public:

   

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<int>ro={1,1,-1,-1};
      vector<int>col={1,-1,-1,1};
      set<int,greater<int>>st;

      auto f=[&](auto &&self,int i, int j,int curlen, int &len, int &sm,bool &reached, int &cnt,int &si,int &sj,int mod){
        if(i>=n || j>=m || i<0 || j<0) return ;
        if(i==si and j==sj and (cnt== 4*len)){
            reached=true;
        
            return ;
        }
        if(curlen==0){
            mod=(mod+1)%4;
            sm+=grid[i][j];
            cnt++;
            self(self,i+ro[mod],j+col[mod],len-1,len,sm,reached,cnt,si,sj,mod);
        }
        else{
            sm+=grid[i][j];
            cnt++;
            self(self,i+ro[mod],j+col[mod],curlen-1,len,sm,reached,cnt,si,sj,mod);
        }
        return;
      };
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            st.insert(grid[i][j]);
            // if it's possible?
            
            int maxhor = min({j, m - 1 - j, (n - 1 - i) / 2});
            
            for(int len=1;len<=maxhor;len++){
                int sm=0;
                bool reached=false;
                int cnt=0;
                f(f,i,j,len,len,sm,reached,cnt,i,j,0);
                // cout<<i<<" "<<j<<" "<<len<<" "<<reached<<" "<<sm<<endl;
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

