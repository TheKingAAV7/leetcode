#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
       
       priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(ll i:nums){
            pq.push(i);
        }
        if(n<2){
            return pq.top()>=k;
        }
        int cnt=0;
        while(pq.size()>=2){
            if(pq.top()>=k){
                break;
            }
            ll a=pq.top();
            pq.pop();
            ll b=pq.top();
            pq.pop();
            pq.push(min(a,b)*2+max(a,b));
            cnt++;
        }
        return cnt;
    }
};