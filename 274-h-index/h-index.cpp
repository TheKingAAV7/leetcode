class Solution {
public:
    int hIndex(vector<int>& c) {
        int low=0,high=c.size();
        int n=c.size();
        int ans=0;
        auto f=[&](int mid)->bool{
            int cnt=0;
            for(int i=0;i<n;i++){
                if(c[i]>=mid)cnt++;
            }
            return cnt>=mid;
        };
        while(low<=high){
            int mid=(low+high)>>1;
            if(f(mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};