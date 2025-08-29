#define ll long long
class Solution {
ll f(string &s){
    ll ans=0;
    int n=s.length();
    ll ts=0;
    for(char c:s){
        if(c=='T') ts++;
    }
    ll ls=0;
    for(char c:s){
        if(c=='L') ls++;
        else if(c=='T') ts--;
        else if(c=='C'){
            ans+=(ls*ts);
        }
    }
    return ans;
}
public:
    long long numOfSubsequences(string s) {
        string s1="L"+s;
        string s2=s+"T";
        ll ans1=f(s1);
        ll ans2=f(s2);
        ll ans3=f(s);

    ll maxi=0;
    int n=s.length();
    ll ts=0;
    for(char c:s){
        if(c=='T') ts++;
    }
    ll ls=0;
    for(char c:s){
        if(c=='L') ls++;
        else if(c=='T') ts--;
        
        maxi=max(maxi,ls*ts);
    }
    ll ans=max({ans1,ans2,ans3+maxi});
    return ans;


    }
};