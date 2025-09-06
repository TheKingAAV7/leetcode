#define ll long long
class Solution {
public:
    long long minOperations(vector<vector<int>>& q) {
        /*

        dividing by 4 shifts the bits by 2..
        
        1-3   1
        4-15  2
        16-63 3
            lef max rig min
         (2-6)  (1-3)  2 3
        2 3 4 5 6
        */
        ll sm=0;
        for(auto it:q){
            ll lef=it[0];
            ll rig=it[1];
            ll tmp=0;
            map<ll,ll>mp;
            for(ll i=1;i<=15;i++){
                ll rlef=pow(4,i-1);
                ll rrig=pow(4,i)-1;
                ll cntlef=max(rlef,lef);
                ll cntrig=min(rrig,rig);
                ll diff=(cntrig-cntlef+1);
                if(diff>=1){
                    //cout<<cntlef<<" "<<cntrig<<endl;
                mp[i]=diff;
                }
               // cout<<rlef<<" "<<rrig<<" "<<i<<endl;
                
            }
            // cout<<endl;
            // for(auto it1:mp) cout<<it1.first<<" "<<it1.second<<endl;
            
            long long totalLevels = 0;
            long long maxLevel = 0;
            for (auto &p : mp) {
                totalLevels += p.first * p.second;   
                maxLevel = max(maxLevel, p.first);
            }
            tmp = (totalLevels + 1) / 2; 
            sm+=tmp;
        }
        return sm;

    }
};