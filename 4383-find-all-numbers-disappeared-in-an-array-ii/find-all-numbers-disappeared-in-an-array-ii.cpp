class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int>st(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int l, r;
        l=INT_MAX;
        r=INT_MIN;
        for(int i=lower;i<=upper;i++){
            if(st.count(i)) {
                if(r!=INT_MIN) ans.push_back({l,r});
                l=INT_MAX;
                r=INT_MIN;
                continue;
            }
            l=min(l,i);
            r=max(r,i);
        }

        if(r!=INT_MIN) ans.push_back({l,r});
        return ans;

    }
};