class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans= 0;
        int n=nums1.size();
        int m=nums2.size();
        reverse(nums1.begin(),nums1.end());
        for(int j=0;j<m;j++){
            auto it= upper_bound(nums1.begin(),nums1.end(),nums2[j]);
            if(it!=nums1.begin()){
            it--;
            int idx= it-nums1.begin();
            // cout<<idx<<" "<<(n-idx-1)<<endl;
            ans= max(ans,j-(n-idx-1));
            }
        }
        return ans;
    }
};