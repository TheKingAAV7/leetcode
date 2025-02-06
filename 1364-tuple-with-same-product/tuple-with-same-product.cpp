class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sm=nums[i]*nums[j];
               // cout<<sm<<" ";
                
                mp[sm]++;
            }
           
        }
        for(auto it:mp){
            if(it.second>1){
                int tmp=(it.second*(it.second-1))/2;
                ans+=(tmp*8);
            }
        }
        return ans;

    }
};