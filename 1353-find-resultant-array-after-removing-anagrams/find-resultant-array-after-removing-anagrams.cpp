class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>arr(words.begin(),words.end());
        
        for(auto &it:words){
            sort(it.begin(),it.end());
        }
        vector<string>st;
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            if(st.empty() || st.back()!=words[i]){
                st.push_back(words[i]);
                ans.push_back(arr[i]);
            }
        }
        return ans;
        
    }
};