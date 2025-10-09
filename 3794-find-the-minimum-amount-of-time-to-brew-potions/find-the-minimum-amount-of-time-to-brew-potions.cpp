class Solution {
public:
#define ll long long
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        // first iteration
        vector<ll>v(n+1,0);
        for(int i=0;i<n;i++){
            v[i+1]=v[i]+(skill[i]*mana[0]);
        }
        vector<vector<ll>>pref(m,vector<ll>(n,0));
        for(int i=0;i<m;i++){
            ll sm=0;
            for(int j=0;j<n;j++){
                sm+=(mana[i]*skill[j]);
                pref[i][j]=sm;
                //cout<<pref[i][j]<<" ";
            }
           //cout<<endl;

        }
        //cout<<endl;


        // for(int i=0;i<=n;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        for(int i=1;i<m;i++){
            ll strt=0;
            for(int j=n-2;j>=0;j--){

                ll dealy=pref[i][j];
                //cout<<i<<" "<<j<<" "<<dealy<<" "<<v[j+2]<<endl;
                
               strt=max({strt,v[j+2]-dealy});
            }
            v[0]=max(v[1],strt);
           // cout<<v[0]<<endl;
            for(int j=0;j<n;j++){
            v[j+1]=v[j]+(skill[j]*mana[i]);
            }
            // for(int j=0;j<=n;j++){
            //    cout<<v[j]<<" ";
            // }
            // cout<<endl;

        }
        return v[n];
    }
};