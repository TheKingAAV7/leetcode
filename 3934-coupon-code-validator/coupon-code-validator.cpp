class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        unordered_set<string>st={"electronics", "grocery", "pharmacy", "restaurant"};
        vector<array<string,2>>tmp;
        for(int i=0;i<n;i++){
            int isalpha= (code[i]=="")?0:1;
            for(char c:code[i]){
                if(!((c>='A' and c<='Z') || (c>='a' and c<='z') || (c>='0' and c<='9') || (c=='_')) ){
                    isalpha=0;
                    break;
                }
            }
            bool bl= (st.find(businessLine[i])!=st.end())?true:false;
            if(isActive[i] and isalpha and bl) tmp.push_back({businessLine[i],code[i]});

        }
        sort(tmp.begin(),tmp.end());
        vector<string>ans;
        for(auto &it:tmp) ans.push_back(it[1]);
        return ans;
    }
};