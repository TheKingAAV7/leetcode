class Solution {
public:
    int numWays(string s) {
        /*
        1) all ones should be same in s1 , s2 and s3
        2) zeros can be different e.g 100 0001 1000000
        3) we have to find the no. of ways to split the string
        
        obs:
        1) no. of 1s must be divisible by 3
        2)if no 1s -> our answer is just
        0000000  there will (n-1) positions to select so, our answer will be 
        (n-1)C2 =(n-1)*(n-2)/2 -> correct
        3) select a shortest middle string which contains exactly (n/3) ones
        means position where cnt of one becomes (n/3+1)...(2n/3)
        pick one just to the right and just to the left;
        (diff1)*(diff2) should be our answer
        */
        int mod=1e9+7;
        int n=s.length();
        int onecnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') onecnt++;
        }
        if(onecnt==0){
            long long ans = (1ll*n-1)%mod*(1ll*n-2)%mod%mod;
            ans = ans * ((mod + 1) / 2) % mod; 
            return ans;
        }
        if(onecnt%3!=0) return 0;
        int req=onecnt/3;
        //cout<<req<<endl;
        onecnt=0;
        int lef=-1,rig=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1') onecnt++;
            if(onecnt==req+1){ 
                if(lef==-1)
                lef=i;
            }
            if(onecnt==req*2){ 
                if(rig==-1) 
                rig=i;
            }
            
        }
        int lidx,ridx;
        lidx=lef-1;
        ridx=rig+1;
        while(lidx>=0 and s[lidx]=='0') lidx--;
        while(ridx<n and s[ridx]=='0') ridx++;

        // cout<<lidx<<" "<<lef<<" "<<rig<<" "<<ridx<<endl;
        int lefrange=(lef-lidx);
        int rigrange=(ridx-rig);
        long long ans=(1ll*lefrange*rigrange)%mod;

        return (int)ans;
    }
};