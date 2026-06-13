class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto &it:words){
            int cur=0;
            for(char &c:it){
                cur= (cur+(weights[c-'a']))%26;
            }
            
            ans.push_back((25-cur)+'a');
        }
        return ans;
    }
};