class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>d1(n),d2(n);
        for(int i=0;i<n;i++){
            d1[i]=nums2[i]-nums1[i];
            d2[i]= (-1)*d1[i];
        }
        int maxi1=accumulate(nums1.begin(),nums1.end(),0);
        int maxi2=accumulate(nums2.begin(),nums2.end(),0);
        int sm1=0,sm2=0;
        int tsm1=0,tsm2=0;
      
        for(int i=0;i<n;i++){
            sm1+=d1[i];
            if(sm1<0){   
                sm1=0;
            }
            tsm1=max(sm1,tsm1);

        }
        for(int i=0;i<n;i++){
            sm2+=d2[i];
            if(sm2<0) sm2=0;
            tsm2=max(sm2,tsm2);
        }
        return max(tsm1+maxi1,tsm2+maxi2);
    }
};