#define ll long long
class Solution {
public:
    long long maxWeight(vector<int>& pz) {
        int n=pz.size();
        cout<<n<<endl;
        sort(pz.begin(),pz.end());
        // for(int i:pz) cout<<i<<" ";
        // cout<<endl;
        ll tmp=n/4;
        if(tmp==1) return pz.back();
        
        int od=ceil(1.0*tmp/2.0);
        int ev=tmp-od;
        ll ans=0;
        while(od--){
            ans+=pz.back();
            pz.pop_back();
        }
        while(ev--){
            pz.pop_back();
            ans+=pz.back();
            pz.pop_back();
        }
      
       
        return ans;


/*
Stdout
12
9 10 11 12 13 15 15 16 18 20 


*/
    }
};