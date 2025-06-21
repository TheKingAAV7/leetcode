class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int>mp;
        for(auto c:word) mp[c]++;
        int ans=word.length();
        for(auto i:mp){
            int cur=0;
            for(auto j:mp){
                if(j.second<i.second){
                    cur+=(j.second);
                }
                if((j.second-i.second)>k){
                    cur+=(j.second-i.second-k);
                }
            }
            ans=min(ans,cur);
        }
        return ans;
    }
};