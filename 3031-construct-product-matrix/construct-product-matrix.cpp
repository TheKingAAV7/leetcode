#define ll long long
class Solution {
public:
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ll MOD=12345;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<ll>>pref(n,vector<ll>(m,1ll));
        vector<vector<ll>>suff(n,vector<ll>(m,1ll));
        vector<vector<ll>>up(n,vector<ll>(m,1ll));
        vector<vector<ll>>down(n,vector<ll>(m,1ll));
        vector<vector<ll>>right(n,vector<ll>(m,1ll));
        vector<vector<ll>>left(n,vector<ll>(m,1ll));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0)
                up[i][j]= (up[i-1][j]*grid[i][j])%MOD;
                else up[i][j]=grid[i][j]%MOD;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j-1>=0)
                left[i][j]= (left[i][j-1]*grid[i][j])%MOD;
                else left[i][j]=grid[i][j]%MOD;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(j+1<m)
                right[i][j]= (right[i][j+1]*grid[i][j])%MOD;
                else right[i][j]=grid[i][j]%MOD;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i+1<n)
                down[i][j]= (down[i+1][j]*grid[i][j])%MOD;
                else down[i][j]=grid[i][j]%MOD;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<right[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll corner= (i-1>=0 and j-1>=0)?pref[i-1][j-1]:1ll;
                ll ups= (i-1>=0)?up[i-1][j]:1ll;
                ll lef= (j-1>=0)?left[i][j-1]:1ll;
                pref[i][j]= (corner*ups*lef*grid[i][j])%MOD;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ll corn= (i+1<n and j+1<m)?suff[i+1][j+1]:1ll;
                ll dwn=(i+1<n)?down[i+1][j]:1ll;
                ll rig= (j+1<m)?right[i][j+1]:1ll;
                suff[i][j]= (corn*dwn*rig*grid[i][j])%MOD;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<pref[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++) cout<<suff[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        vector<vector<int>>ans(n,vector<int>(m,1ll));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll ups= (i-1>=0)?pref[i-1][m-1]:1ll;
                ll dwn= (i+1<n)?suff[i+1][0]:1ll;
                ll lef= (j-1>=0)?left[i][j-1]:1ll;
                ll rig= (j+1<m)?right[i][j+1]:1ll;
                // if(i==0 and j==0) cout<<ups<<" "<<dwn<<endl;
                ans[i][j]= (ups*dwn*lef*rig)%MOD;
            }
        }
        return ans;
        
    }
};