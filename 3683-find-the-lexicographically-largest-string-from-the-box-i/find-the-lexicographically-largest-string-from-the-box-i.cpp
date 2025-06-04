class Solution {
public:
    string answerString(string word, int k) {
        int n=word.length();
        int len=n-(k-1);
        if(k==1){
            return word;
        }
       // cout<<len<<endl;
        string ans="";
        for(int i=0;i<n;i++){
            string tmp=word.substr(i,len);
          //  cout<<tmp<<endl;
            if(ans==""){
                ans=tmp;
            }
            else ans=max(ans,tmp);
        }
        return ans;


        
    }
};