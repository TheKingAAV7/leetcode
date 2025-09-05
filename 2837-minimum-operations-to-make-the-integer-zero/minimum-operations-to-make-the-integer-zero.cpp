#define ll long long
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans=INT_MAX;
        if(num2>=num1) return -1;

        for(int i=1;i<=60;i++){
            ll tmp= num1- (1ll*i*num2);
            if(tmp>0){
                ll sb= __builtin_popcountll(tmp);
                if(tmp==1){
                 //   cout<<"YES"<<endl;
                    if(i==1) return i;
                }
                else{
            
            if(sb<=i){
                return i;
            }
                }
            }
        }
        return -1;
    }
};