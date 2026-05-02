class Solution {
public:
    int rotatedDigits(int n) {
        set<int>st={1,0,8};
        int cnt=0;
        set<int>invalid={3,4,7};
        for(int i=1;i<=n;i++){
            int x=i;
            bool changed=false;
            bool valid=true;
            while(x>0){
                int cur= x%10;
                x/=10;
                if(st.find(cur)==st.end()){
                    changed=true;
                    if(invalid.find(cur)!=invalid.end()){
                        valid=false;
                        break;
                    }
                }

            }
            if(valid and changed) cnt++;
        }
        return cnt;
    }
};