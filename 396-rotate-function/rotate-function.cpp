#define ll long long
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n= nums.size();
        /*
        4 3 2 6 4 3 2 6

        4*0 3*1 2*2 6*3
        3+2+6-12
        3*0 2*1 6*2 4*3

      
      sm - (3*1+2*2+6*3)  25
            3*0+2*1+6*2   14
        */
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        ll sm=accumulate(nums.begin(),nums.begin()+n,0ll);
        ll mx=0;
        ll cur=0;
        for(int i=0;i<n;i++){
            cur+=(i*nums[i]);
        }
        mx=cur;
        for(int i=1;i<n;i++){
            // cout<<cur<<endl;
            ll rigsm= sm-nums[i-1];
            // cout<<rigsm<<endl;
            ll tosub= rigsm- ((n-1)*nums[i-1]);
            ll nxtsm= cur-tosub;
            // cout<<rigsm<<" "<<tosub<<" "<<nxtsm<<endl;
            mx=max(mx,nxtsm);
            cur=nxtsm;
            sm-=nums[i-1];
            sm+=nums[i+n-1];
            

        }
        return mx;
    }
};