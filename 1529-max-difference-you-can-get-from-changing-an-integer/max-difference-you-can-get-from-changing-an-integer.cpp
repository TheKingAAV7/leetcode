class Solution {  // 99 - 11
public:
    int maxDiff(int num) {
     string tmp=to_string(num);
        int n=tmp.length();
        int pos=0;
        while(pos<n and tmp[pos]=='9') pos++;
        
        if(pos==n){
            string ans="";
            for(int i=0;i<n;i++){
                ans.push_back('8');
            }
            return stoi(ans);
        }
        int pos1=0;
        while(pos1<n and (tmp[pos1]=='1'|| tmp[pos1]=='0')){
            pos1++;
        }  
       
        string a1=tmp, b1=tmp;
        for(int i=0;i<n;i++){
            if(pos<n and a1[i]==tmp[pos]) a1[i]='9';
            if(pos1<n and b1[i]==tmp[pos1]) {
                if(pos1==0) b1[i]='1';
                else b1[i]='0';
            }
        }
        int a=stoi(a1);
        int b=stoi(b1);
      
       //1101057
       //9909057
        return a-b;
    }
};