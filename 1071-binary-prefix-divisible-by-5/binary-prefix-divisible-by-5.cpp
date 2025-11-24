class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int cur=0;
        // 1 0 1     1 2 5
        int n=nums.size();
        vector<bool>ans(n,0);
        for(int i=0;i<n;i++){
            cur<<=1;
            cur|= nums[i];
            if(cur%5==0){
                ans[i]=true;
            }
            cur=cur%5;
        }
        return ans;
        /*

        101
        1010
        1111
        10100
        11001


        */
        return ans;
    }
};