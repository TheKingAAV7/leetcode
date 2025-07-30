#define ll long long
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<ll>ans;
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        vector<ll>pref(n,0);
        ll tsm=0;
        for(int i=0;i<n;i++){
            tsm+=nums[i];
            pref[i]=tsm;
        }
       
        for(auto it:queries){
           auto it1=lower_bound(nums.begin(),nums.end(),it);
           ll idx=it1-nums.begin();
           idx--;
           //cout<<idx<<endl;
           ll sm=0;
           if(idx==(-1)){
            sm+=(tsm-(it*n));
           }
           else{
            if(idx==n-1){
                sm+=((it*n)-(tsm));
            }
            else{
             
                ll nele=idx+1;
                sm+=((nele*it)-(pref[idx]));
                ll rem=n-nele;
                sm+=((tsm-pref[idx])-(rem*it));
            }
           }
           ans.push_back(sm);

        }
        return ans;
    }
};