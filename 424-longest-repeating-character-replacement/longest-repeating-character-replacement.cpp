class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int ans=0;
        for(char c='A';c<='Z';c++){
            int cost=0;
            int l=0;
            for(int i=0;i<n;i++){
                if(s[i]!=c){
                    cost++;
                }
                while(cost>k){
                    if(s[l]!=c) cost--;
                    l++;
                }
                ans=max(ans,i-l+1);
            }
        }
        return ans;
    }
};