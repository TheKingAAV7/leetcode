class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // there should be a smaller element of opposite parity
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        int par0,par1;
        par0=par1=0;
        bool one,two;
        // odd to even not possible
        // ev-> od = od
         // 1 2 3 4
        set<int>st;
        for(int i:nums1) st.insert(i&1);
        if(st.size()==1) return true;
        one=two=true;
        for(int i=0;i<n;i++){
           if(nums1[i]%2==0){
               if(!par1){
                   one=false;
                   break;
               }
           }
            if(nums1[i]%2) par1=true;
        }
        return one;
       
    }
};