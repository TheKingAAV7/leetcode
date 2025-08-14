class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.length();
        string ans="";
        for(int i=0;i<n-2;i++){
            string tmp=num.substr(i,3);
            if(tmp[0]==tmp[1] and tmp[1]==tmp[2]){
               // cout<<tmp<<endl;
                if(ans=="") ans =tmp;
                else {
                    if(tmp>ans) ans=tmp;
                }
            }
        }
        return ans;
    }
};