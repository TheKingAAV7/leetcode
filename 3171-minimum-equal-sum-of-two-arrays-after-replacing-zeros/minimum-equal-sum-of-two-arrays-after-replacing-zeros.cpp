class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cnt1=0;
        int cnt2=0;
        long long sm1=0,sm2=0;
        for(int i:nums1) {
        sm1+=i;
        if(i==0) cnt1++;
        }
        for(int i:nums2) {
            sm2+=i;
        if(i==0) cnt2++;
        }

        if(cnt1!=0 and cnt2!=0) return max(sm1+cnt1,sm2+cnt2);
        if(cnt1==0 and cnt2==0){
            if(sm1==sm2) return sm1;
            else return -1;
        }
        if(cnt1==0){
            sm2+=cnt2;
            if(sm2<=sm1) return sm1;
            return -1;
        }
        if(cnt2==0){
            sm1+=cnt1;
            if(sm1<=sm2) return sm2;
            return -1;
        }
        
        return -1;
    }
};