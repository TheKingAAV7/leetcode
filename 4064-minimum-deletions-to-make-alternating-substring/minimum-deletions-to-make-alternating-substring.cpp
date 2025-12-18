class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n=s.length();
        int B= ceil(sqrt(1.0*n));
        vector<int>dp(B,0);
        vector<int>ans;

        function<int(int, int)>query=[&](int l, int r){
            int b1= l/B;
            int b2= r/B;
            if(b1==b2){
               
                int cnt=0;
                for(int i=l+1;i<=r;i++){
                    cnt+=(s[i]==s[i-1]);
                }
                return cnt;
            }
            int cnt=0;
            for(int i=b1+1;i<b2;i++){
                int strt= i*B;
                int prev= strt-1;
                if(s[prev]==s[strt]) cnt++;
                cnt+=dp[i];
            }
           
            int lstrt= l;
            int lend= min(((b1)*B + B-1), n-1);

            int rstrt= b2*B;
            int rend= r;
            for(int i=lstrt+1;i<=lend;i++){
                cnt+=(s[i]==s[i-1]);
            }
            for(int i=rstrt;i<=rend;i++){
                if(i>=1) cnt+=(s[i]==s[i-1]);
            }
            return cnt;

        };

        function<void(int)>update=[&](int idx)->void{
            if(s[idx]=='A') s[idx]='B';
            else s[idx]='A';
            int block=idx/B;
            int start= block*B;
            int end= min(start+B,n);
            int cnt=0;
            for(int i=start+1;i<end;i++){
                if(s[i]==s[i-1]) cnt++;
            }
            dp[block]=cnt;
            return;
        };
        for(int i=1;i<n;i++){
            int block1= i/B;
            int block2= (i-1)/B;
            if(s[i]==s[i-1]){
                if(block1==block2)
                    dp[block1]++;
            }
        }
        for(auto it:queries){
            if(it[0]==1){
                int id=it[1];
                update(id);
            }
            else{
                int lef=it[1];
                int rig=it[2];
                int tmp= query(lef,rig);
                ans.push_back(tmp);

            }
            // int tt=query(0,n-1);
            // cout<<tt<<endl;
            // for(int i:dp) cout<<i<<" ";
            // cout<<endl;
        }
        return ans;
    }
};