class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>st={2,3,5,7,11,13,17,19,23,29,31};
        int ans=0;
        for(int i=left;i<=right;i++){
            int tmp=i;
            int cnt=__builtin_popcount(tmp);
            if(st.find(cnt)!=st.end()) ans++;
        }
        return ans;
    }
};