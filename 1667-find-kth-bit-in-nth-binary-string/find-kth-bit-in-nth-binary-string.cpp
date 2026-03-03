class Solution {
public:
    char findKthBit(int n, int k) {


        char ans;
        function<void(string&,int,int&)>f=[&](string &s, int n,int& k ){
            if(n==0){
                ans=s[k-1];
                return;
            }
            
            string tmp= s;
            reverse(tmp.begin(),tmp.end());
            for(char &c: tmp){
                if(c=='0') c='1';
                else c='0';
            }
            string nstr = s + "1" + tmp;
            f(nstr,n-1,k); 
            return;
        };

        string cur="0";
        if(n==1) return cur[0];
        f(cur,n,k);
        return ans;
    }
};