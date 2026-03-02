class Solution {
public:
    /*
    A row will always be swapped with the row below it..

    */
    int minSwaps(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<int>required;
      int req=m-1;
      for(int i=0;i<n-1;i++){
        required.push_back(req);
        req--;
      }
      auto count=[&](vector<int>&v){
        int cnt=0;
        int pos= v.size()-1;
        while(pos>=0 and v[pos--]==0) cnt++; 
        return cnt;
      };
      int cost=0;
      for(int i=0;i<n-1;i++){
        int have= count(grid[i]);
       // cout<<have<<" "<<required[i]<<endl;
        if(have>=required[i]) continue;
        bool found=false;
        int idx=-1;
        for(int j=i+1;j<n;j++){
            int hav1= count(grid[j]);
            if(hav1>=required[i]){
                found=true;
                idx=j; break;
            }
        }
        if(!found) return -1;
     //   cout<<idx<<endl;
        
        while(idx-1>=i){
            cost++;
            if(idx-1>=i)
            swap(grid[idx],grid[idx-1]);
            
            idx--;
        }
      }
      return cost;
    }
};