class Solution {
public:
    string generateTag(string cap) {
        string ans="";
        ans.push_back('#');
        int i=0;
        int n=cap.size();
        bool f=true;
        while(i<n){
            bool f1=false;
            while(i<n and ((cap[i]>='a' and cap[i]<='z') || (cap[i]>='A' and cap[i]<='Z'))){
                if(!f1){
                    if(f){
                        ans.push_back(tolower(cap[i]));
                        f=!f;
                    }
                    else{
                        ans.push_back(toupper(cap[i]));
                    }

                     f1=!f1;
                }
                else{
                    ans.push_back(tolower(cap[i]));
                }
                i++;
            }
            while(i<n and cap[i]==' ') i++;

        }
        while(ans.size()>100) ans.pop_back();
        return ans;
    }
};