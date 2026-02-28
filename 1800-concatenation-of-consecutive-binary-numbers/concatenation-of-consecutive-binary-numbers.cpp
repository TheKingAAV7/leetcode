class Solution {
public:
    int MOD=1e9+7;

    int concatenatedBinary(int n) {
        int ans=1;
        for(int i=2;i<=n;i++){
            string cur;
            int num=i;
            while(num>0){
                if(num&1) cur.push_back('1');
                else cur.push_back('0');
                num>>=1;
            }
            reverse(cur.begin(),cur.end());
            for(char c: cur){
                if(c=='1'){
                    ans=(ans*2 + 1)%MOD;
                }
                else ans=(ans*2)%MOD;
            }
        }
        return ans;
    }
};