class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        for(int i=0;i<n;i++){
            int x= nums1[i];
            auto it1= lower_bound(nums2.begin(),nums2.end(),x);
            auto it2= upper_bound(nums2.begin(),nums2.end(),x);
            it2--;
            int cnt= it2-it1+1;
            if(cnt>=1) return x;
        }
        return -1;
    }
};