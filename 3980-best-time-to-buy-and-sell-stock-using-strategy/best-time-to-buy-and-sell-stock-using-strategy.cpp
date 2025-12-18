#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll sm= 0;
        int n=prices.size();
        vector<ll>pref(n);
        vector<ll>pref1(n);
        ll psm=0;
        for(int i=0;i<n;i++){
            psm+=prices[i];
            sm+=(prices[i]*strategy[i]);
            pref[i]=sm;
            pref1[i]=psm;
        }
        ll ans= sm;
       
        int l=0,r=k-1;
        while(r<n){
            ll lefsm= (l==0)?0:pref[l-1];
            ll rigsm= sm-pref[r];
            ll halfidx= (l+(k/2)-1);
            ll previnlef=pref[halfidx]-lefsm;
            ll previnrig=pref[r]- pref[halfidx];
            ll inlefsm= pref1[halfidx]- (l==0?0:pref1[l-1]);
            ll inrigsm= pref1[r] - pref1[halfidx];
            ll cur_sm= sm- previnlef - previnrig + inrigsm;
            ans=max(ans,cur_sm);
           
            r++;
            l++;

        }
        return ans;
        
    }
};