class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        int i=0;
        int ans=0;
        while(i<n){
            int cnt1=0;
            int cnt0=0;
            while(i<n and s[i]=='1') {
            cnt1++;
            i++;
            }
            while(i<n and s[i]=='0') {
                i++;
            cnt0++;
            }
            ans+=min(cnt1,cnt0);
        }
        i=0;
        while(i<n){
            int cnt1=0;
            int cnt0=0;
            while(i<n and s[i]=='0'){ 
                i++;
            cnt1++;
            }
            while(i<n and s[i]=='1'){
                i++;
             cnt0++;
            }
            ans+=min(cnt1,cnt0);
        }
        return ans;

    }
};