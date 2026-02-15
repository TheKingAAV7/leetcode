class Solution {
public:
    string addBinary(string a, string b) {
        int num1=0,num2=0;
        int n=a.length();
        int m=b.length();
        int i=n-1,j=m-1;
        string ans;
        int carry=0;
        while(i>=0 and j>=0){
            int b1=a[i]-'0';
            int b2=b[j]-'0';
            if(b1==0 || b2==0){
                int cur= b1+b2;
                if(b1==0 and b2==0){
                    cur=carry;
                    ans.push_back(carry+'0');
                    carry=0;
                }
                else{
                int cur=b1+b2;
                if(carry){
                    cur=0;
                    carry=1;
                }
                ans.push_back(cur+'0');
                }
            }
            else{
                if(carry){
                    ans.push_back('1');
                    carry=1;
                }
                else{
                    ans.push_back('0');
                    carry=1;
                }
            }

            i--;
            j--;
        }
        while(i>=0){
            int b1=a[i]-'0';
            if(carry){
                if(b1==0){
                    ans.push_back('1');
                    carry=0;
                }
                else{
                    ans.push_back('0');
                    carry=1;
                }
            }
            else{
                ans.push_back(a[i]);
            }
            i--;
        }
        while(j>=0){
            int b1=b[j]-'0';
            if(carry){
                if(b1==0){
                    ans.push_back('1');
                    carry=0;
                }
                else{
                    ans.push_back('0');
                    carry=1;
                }
            }
            else{
                ans.push_back(b[j]);
            }
            j--;
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
       
    }
};