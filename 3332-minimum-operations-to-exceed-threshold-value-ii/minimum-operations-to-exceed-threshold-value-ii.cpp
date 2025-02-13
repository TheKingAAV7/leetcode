#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,h=n;
        int ans=-1;
        auto f=[&](int mid)->bool{
            //cout<<mid<<endl;
            priority_queue<ll,vector<ll>,greater<ll>>pq;
            for(ll i:nums)pq.push(i);
            while(mid and pq.size()>=2){
            ll a=pq.top();
            pq.pop();
            ll b=pq.top();
            pq.pop();
            pq.push(min(a,b)*2+max(a,b));
            mid--;
            }
            while(!pq.empty()){
                if(pq.top()<k) return false;
                pq.pop();
            }
            return true;
        };
        while(l<=h){
            int mid=(l+h)>>1;
            if(f(mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};