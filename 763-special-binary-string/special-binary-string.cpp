class Solution {
public:
    string makeLargestSpecial(string s) {
     int n=s.length();
     vector<int>v;
     vector<vector<int>>dp(n,vector<int>(n,0));
     for(int i=0;i<n;i++){
        if(s[i]=='0') continue;
        for(int j=i+1;j<n;j++){               // j must be > i (min length 2)
            int cnt0=0, cnt1=0;
            bool ok=true;
            for(int k=i;k<=j;k++){
                if(s[k]=='0') ++cnt0; else ++cnt1;
                if(cnt0>cnt1){ // invalid: more zeros than ones at some prefix
                    ok=false;
                    break;
                }
                if(k<j && cnt0==cnt1){ 
                    // ensure primitive special substring (no inner zero balance)
                    ok=false;
                    break;
                }
            }
            if(ok && cnt0==cnt1){
             dp[i][j]=1;
            }
        }
     }
     string ans=s;

     function<void(int,vector<int>&, int &)>f=[&](int i, vector<int>&v , int &start){
       
        if(i==n || s[i]=='0'){
            vector<string>tmp;
            v.push_back(i);
            for(int id=0;id<(v.size()-1);id++){
                int lef= v[id];
                int rig= v[id+1];
                int len= rig-lef;
                // ---- MINIMAL CHANGE: recursively process inner part before pushing ----
                if(len == 2) {
                    tmp.push_back("10");
                } else {
                    string inner = s.substr(lef+1, len-2);
                    string sortedInner = makeLargestSpecial(inner); // recursive fix
                    tmp.push_back("1" + sortedInner + "0");
                }
            }

            sort(tmp.begin(),tmp.end(),[&](string &a, string &b){
                string a1= a+b;
                string a2= b+a;
                return a1>a2;
            });
            string cur1;
            for(auto &it:tmp) cur1+=it;
            string left= s.substr(0,start);
            string right= s.substr(i);
            string cand= left+ cur1 + right;
            ans=max(ans,cand);
            v.pop_back();
            return ;
        }

        for(int idx=i;idx<n;idx++){
            if(dp[i][idx]){
                v.push_back(i);
                f(idx+1,v,start);
                v.pop_back();
            }
        }
        return;

     };
     int start = 0;
     f(0, v, start);

     return ans;
     
    }
};