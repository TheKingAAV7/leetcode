class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<vector<string>>ans;
        set<string>st={"electronics", "grocery", "pharmacy", "restaurant"};
        for(int i=0;i<n;i++){
            bool a=true;
            if(code[i].size()==0) a=false;
            for(char ch:code[i]){
                if( !(isalnum(ch) || ch=='_')){
                    a=false;
                    break;
                }
            }

            bool b=false;
                if(st.find(businessLine[i])!=st.end()){
                    b=true;
                }
                if(a and b and isActive[i]){
                    ans.push_back({businessLine[i],code[i]});
                }
            
        }
        sort(ans.begin(),ans.end());
        vector<string>res;
        for(auto it:ans) res.push_back(it[1]);
        return res;
    }
};