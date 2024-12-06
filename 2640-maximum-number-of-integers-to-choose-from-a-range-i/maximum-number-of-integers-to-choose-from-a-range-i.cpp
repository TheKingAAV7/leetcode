class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        int ans=0;
        for(int i=1;i<=n;i++)st.insert(i);
        for(auto i: banned){
            st.erase(i);
        } //  2 3 4 
        int sm=0;
        for(auto it: st){
            if(sm+it<=maxSum){
                ans++;
                sm+=it;
            }
        }
        return ans;
    }
};