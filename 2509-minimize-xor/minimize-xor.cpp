class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0,cnt1=0;
        int b=0;
        int tmp=num2;
        while(tmp>0){
            if(tmp&1){
                cnt++;
            }
            tmp=tmp>>1;
        }
        tmp=num1;
        while(tmp>0){
            if(tmp&1) cnt1++;
            b++;
            tmp=tmp>>1;
        }
        if(cnt==cnt1) return num1;
        //cout<<cnt<<" "<<b<<endl;
        if(cnt>b){
            return pow(2,cnt)-1;
        }
        
            int ans=0;
            for(int i=31;i>=0;i--){
                if((num1>>i)&1){
                    ans|=(1LL<<i);
                    cnt--;
                    if(cnt==0) break;
                }
            }
            cout<<cnt<<endl;
            for(int i=0;i<32;i++){
                if(cnt==0) break;
                
                if(((ans>>i)&1) ==0){
                    ans|=(1LL<<i);
                    cnt--;

                }
            }
            return ans;
            
            
        

    }
};