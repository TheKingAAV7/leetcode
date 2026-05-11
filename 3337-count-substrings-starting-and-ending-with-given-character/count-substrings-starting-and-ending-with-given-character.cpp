class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt=0;
        for(char &cc:s) cnt+=(cc==c);

        return 1ll*cnt*(cnt+1ll)/2ll;
    }
};