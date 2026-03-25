#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<ll>p1(n,0),s1(n,0);
        vector<ll>p2(m,0),s2(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p1[i]+=grid[i][j];
                p2[j]+=grid[i][j];
            }
        }
        
        vector<ll>prefr(n,0),suffr(n,0);
        vector<ll>prefc(m,0),suffc(m,0);
        ll sm=0;
        for(int i=0;i<n;i++){
            sm+=p1[i];
            prefr[i]=sm;
        }
        sm=0;
        for(int i=n-1;i>=0;i--){
            sm+=p1[i];
            suffr[i]=sm;
        }
        sm=0;
        for(int i=0;i<m;i++){
            sm+=p2[i];
            prefc[i]=sm;
        }
        sm=0;
        for(int i=m-1;i>=0;i--){
            sm+=p2[i];
            suffc[i]=sm;
        }
        for(int i=0;i<n-1;i++){
            if(prefr[i]==suffr[i+1]) return true;
        }
        for(int i=0;i<m-1;i++){
            if(prefc[i]==suffc[i+1]) return true;
        }
        // for(int i:p1) cout<<i<<" ";
        // cout<<endl;
        // cout<<endl;
        // for(int i:p2) cout<<i<<" ";
        // cout<<endl;
        // cout<<endl;
        
        return false;
        
    }
};