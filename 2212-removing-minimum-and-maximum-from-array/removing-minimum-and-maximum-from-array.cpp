class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int mini= *min_element(nums.begin(),nums.end());
        int maxi= *max_element(nums.begin(),nums.end());
        
        int mn,mx;
        
        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                mn=i;
            }
            else if(nums[i]==maxi){
                mx=i;
            }
        }
        int lef= min(mx,mn);
        int rig=max(mx,mn);
        // lef, rig,   only lef, only rig
        int ans1= (lef+1) + (n-rig);
        int ans2= rig+1;
        int ans3= (n-lef);
        return min({ans1,ans2,ans3});

    }
};