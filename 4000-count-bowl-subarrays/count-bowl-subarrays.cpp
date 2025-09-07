#define ll long long
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        //  2 5 3 1 4   
        ll ans=0;
        ll n =nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            ll x=nums[i];
            while(!st.empty() and nums[st.top()]<=x){
                ll idx=st.top();
                if(i-idx+1>=3){
                    ans++;
                }
                 st.pop();
            }
            if(!st.empty() and ((i-st.top()+1) >=3)) ans++;
            st.push(i);
        }
        return ans;
    }
};