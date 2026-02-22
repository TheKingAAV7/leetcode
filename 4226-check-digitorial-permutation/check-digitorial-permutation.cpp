class Solution {
public:
    bool isDigitorialPermutation(int n) {
        
        string num=to_string(n);
        int sm=0;
        auto fact=[&](int x)->int{
            int ans=1;
            for(int i=1;i<=x;i++) ans*=i;
            return ans;
        };
        while(n>0){
            sm+=fact(n%10);n/=10;
        }
        string s= to_string(sm);
        sort(num.begin(),num.end());
        sort(s.begin(),s.end());
        //cout<<s<<" "<<num<<endl;
        return s==num;
    }
};