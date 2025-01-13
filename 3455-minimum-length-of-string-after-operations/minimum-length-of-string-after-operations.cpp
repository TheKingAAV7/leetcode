class Solution {
public:
    int minimumLength(string s) {
        vector<int>v(26,0);
        for(auto c:s){
            v[c-'a']++;
        }
        int ans=0;
        for(int i:v){
            if(i!=0){
                if(i%2) ans++;
                else ans+=2;
            }
        }
        return ans;
    }
};