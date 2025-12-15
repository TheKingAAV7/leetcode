#define ll long long
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans=0;
        ll cnt=0;
        int prev=1e9+1;
        int n=prices.size();
        for(int i=0;i<n;i++){
            
            if(prev==(1e9+1) || prev-1==prices[i]){
                cnt++;
                prev=prices[i];
            }
            else{
             
                ans+=  (cnt*(cnt+1))/2;
                cnt=1;
                prev=prices[i];
            }
        }
        ans+=(cnt*(cnt+1))/2;
        return ans;
    }
};