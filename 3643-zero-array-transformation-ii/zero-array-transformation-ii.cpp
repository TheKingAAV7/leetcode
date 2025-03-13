class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
     int n=nums.size();
     int m=queries.size();
     int lo=0,hi=m;
     int ans=-1;
     auto f=[&](int k)->bool{
        vector<int>tmp(n+1,0);
        for(int i=0;i<k;i++){
            tmp[queries[i][0]]-=queries[i][2];
            tmp[queries[i][1]+1]+=queries[i][2];
        }
        
        for(int i=1;i<n;i++){
            tmp[i]+=(tmp[i-1]);
        }
      
        
        for(int i=0;i<n;i++){
            if(nums[i]+tmp[i]>0) return false;
        }
        return true;
     };
     while(lo<=hi){
        int mid=(lo+hi)>>1;
        if(f(mid)){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
     }
     return ans;
    }
};