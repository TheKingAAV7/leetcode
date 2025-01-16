class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n%2==0 and m%2==0) return 0;
        if(n%2==1 and m%2==1){
            int xo=0;
            for(int i:nums1)xo^=i;
            for(int i:nums2)xo^=i;
            return xo;
        }
        if(n%2){
            int xo=0;
            for(int i:nums2) xo^=i;
            return xo;
        }
        int xo=0;
        for(int i:nums1) xo^=i;
        return xo;

    }
};