class Solution {
private:
        long long solve(int i,bool tight,string &str,int limit,string &s,vector<vector<long long>> &dp){
                if(i==str.length()){
                        return 1;
                }
                if(dp[i][tight]!=-1) return dp[i][tight];
                int l = limit;
                if(tight && ((str[i]-'0') <= limit)){
                        l = str[i]-'0';
                }
                long long ans = 0;
                for(int j = 0 ; j <= l ; j++){
                        if(i>=(str.length()-s.length())){
                                if(!tight){
                                        return 1;
                                }
                                else{
                                        if(stoll(str.substr(i)) >= stoll(s)) return 1;
                                }
                        }
                        else{
                                bool newtight = (tight==true && (j==(str[i]-'0')));
                                ans = ans+solve(i+1,newtight,str,limit,s,dp);
                        }
                }
                return dp[i][tight] = ans;
        }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string st = to_string(start-1);
            string f = to_string(finish);
            vector<vector<long long>> dp(f.length()+1,vector<long long>(2,-1));
           long long ans = solve(0,true,f,limit,s,dp);
            vector<vector<long long>> dp2(f.length()+1,vector<long long>(2,-1));
            if(st.length() >= s.length()) ans = ans-solve(0,true,st,limit,s,dp2);
            return ans;
    }
};