class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string tmp="";
        while(num1>0 and num2>0 and num3>0){
            int a=num1%10;
            int b=num2%10;
            int c=num3%10;
            tmp.push_back(min({a,b,c})+'0');
            num1/=10;
            num2/=10;
            num3/=10;
        }
        reverse(tmp.begin(),tmp.end());
        return stoi(tmp);
    }
};