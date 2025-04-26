class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        vector<int>v(n,-1);
        int pos=-1;
        for(int i=n-1;i>=0;i--){
          
            v[i]=pos;
            if(nums[i]<minK || nums[i]>maxK){
               
                pos=i;
            }
        }

     

        int l=0;
        map<int,int>mp;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
               // cout<<i<<endl;
                mp.clear();
                l=i+1;
                continue;
            }
            mp[nums[i]]++;
           // cout<<(mp.begin()->first)<<" "<<((prev(mp.end()))->first)<<endl;
            while((mp.begin()->first)==minK and ((prev(mp.end()))->first)==maxK){
                 
                if(v[i]==-1){
                    ans+=(n-i);
                }
                else{
                    ans+=(v[i]-i);
                }
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
        }
        return ans;
        
    }
};