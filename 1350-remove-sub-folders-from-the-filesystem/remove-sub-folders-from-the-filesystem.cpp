class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(),folder.end(),[&](string &a, string &b){
            return a.length()<b.length();
        });
        vector<string>ans;
        unordered_set<string>st;
        for(auto it:folder){
            string tmp="";
            bool f=false;
            for(auto c:it){
                if(c=='/'){
                if(st.find(tmp)!=st.end()){
                    f=true;
                    break;
                }
                }
                tmp.push_back(c);
                
            }
            if(!f){
                ans.push_back(tmp);
                st.insert(tmp);
            }
        }
        return ans;
    }
};