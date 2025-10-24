class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sm=0;
        for(int i:nums){
            sm+=(double)(i);
        }
        int start=1;
        
        int n=nums.size();
        double cand=1.0*(sm)/n;
        int tmp= ceil(cand);
        if(ceil(cand)==floor(cand)) tmp++;
        start=max(start,tmp);
        set<int>st(nums.begin(),nums.end());
        while(st.find(start)!=st.end()){
            start++;
        }
        return start;

    }
};