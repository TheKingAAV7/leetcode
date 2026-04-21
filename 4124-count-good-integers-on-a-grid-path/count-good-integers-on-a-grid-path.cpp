#define ll long long
class Solution {
public:
    vector<vector<int>>mat={
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11},
        {12,13,14,15}
    };
    set<int>st;
    const int MX=17;
    vector<vector<vector<ll>>> dp;
     Solution() {
        
    }
    

    ll f(int i, string &s, int tight, int &n,int prev,string &tmp){
        if(i>=n){
            // cout<<tmp<<endl;
         return 1ll;
        }
        int cp= prev+1;
        if( dp[i][tight][cp]!=-1) return dp[i][tight][cp];
        // cout<<"UES"<<endl;
        // int ans=0;
        bool yes=false;
        if(st.find(i)!=st.end()){
         yes= true;
        }

        int mx= (tight==1)?(s[i]-'0'):9;
        int mn=  0;
        if(yes){
            if(prev==-1) mn=0;
            else mn= prev;
        }
        // cout<<mn<<" "<<mx<<endl;
        ll ans=0;
        for(int cur=mn;cur<=mx;cur++){
        //  tmp.push_back(cur+'0');
         int nxtp= (yes)?cur:prev;
         ans+=f(i+1,s,(tight and cur==mx),n,nxtp,tmp);
        //  tmp.pop_back();
        }
        return dp[i][tight][cp]=ans;
    }
    ll caller(ll num){
        string s= to_string(num);
        reverse(s.begin(),s.end());
        while(s.length()<16) s.push_back('0');
        reverse(s.begin(),s.end());
        // cout<<s<<endl;
        int n=16;
        string tmp;
        dp = vector<vector<vector<ll>>>(MX, vector<vector<ll>>(2, vector<ll>(MX, -1LL)));
        return f(0,s,1,n,-1,tmp);
    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        st.clear();
        int x=0, y=0;
        st.insert(0);
        for(char c:directions){
            if(c=='D'){
                x++;
            }
            else if(c=='R'){
                y++;
            }
            else if(c=='U'){
                x--;
            }
            else{
                y--;
            }
            st.insert(mat[x][y]);
        }

        // for(int i:st) cout<<i<<" ";
        // cout<<endl;
        
        
        return caller(r)- caller(l-1);
    }
};