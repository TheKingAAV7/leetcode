class Solution {
public:
    vector<vector<vector<vector<int>>>>dp;
    unordered_set<int>st={2,3,5,7,11,13,17,19,23,29,31};
    int f(int i, int leading_zero,int tight,int cnt,int &len,string &s){
        if(i>=len){
            if(st.find(cnt)!=st.end()) return 1;
            return 0;
        }
        if(dp[i][leading_zero][tight][cnt]!=-1) return dp[i][leading_zero][tight][cnt];
        int mx= tight?(s[i]-'0') : 1;
        int ans=0;
        for(int cur=0;cur<=mx;cur++){
            
                ans+=f(i+1,leading_zero && (cur==0), tight && (cur==mx),cnt+cur,len,s);
            
        }
        return dp[i][leading_zero][tight][cnt]=ans;

    }

    int caller(int num){
        if(num==-1) return 0;


        string s;
        for(int i=0;i<31;i++){
            if((num>>i)&1) s.push_back('1');
            else s.push_back('0');
        }
        reverse(s.begin(),s.end());
        int len=31;
          dp.assign(len, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(32, -1))));
        
        return f(0,1,1,0,len,s);
        
    }
    int countPrimeSetBits(int left, int right) {

        // state-> idx,leading_zero,tight,cnt,  



        int ans= caller(right) - caller(left-1);
       
        return ans;
    }
};