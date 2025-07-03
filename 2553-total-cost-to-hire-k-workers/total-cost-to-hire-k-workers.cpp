class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        multiset<long long>a,b;
        int n=costs.size();
        int pos=cand;
        for(int i=0;i<cand;i++) a.insert(costs[i]);
        int rig=n;
        for(int i=n-1;i>=cand;i--){
            b.insert(costs[i]);
            rig=i;
            if(b.size()==cand) break;
        }
        int lef=cand;
        rig--;
        // for(int i:a) cout<<i<<" ";
        // cout<<endl;

        // for(int i:b) cout<<i<<" ";
        // cout<<endl;
        // cout<<lef<<" "<<rig<<endl<<endl;
        long long ans=0;
        while(k--){
            int amn= INT_MAX;
            int bmn= INT_MAX;
            if(a.size()>=1) amn= *a.begin();
            if(b.size()>=1) bmn= *b.begin();
            if(amn<=bmn){
                ans+=amn;
                a.erase(a.begin());
                
                
                if(lef<=rig) {
                a.insert(costs[lef]);
                lef++;
                }
            }
            else{
                ans+=bmn;
                //ans+=bmn;
                b.erase(b.begin());
                
                if(lef<=rig){
                    b.insert(costs[rig]);
                    rig--;
                }
            }
    
        }
        return ans;

    }
};