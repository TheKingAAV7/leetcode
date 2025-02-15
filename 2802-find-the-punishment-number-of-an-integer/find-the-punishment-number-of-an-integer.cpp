class Solution {
private:
bool f(string s, long long i, long long tmp,int ind,int n,long long final){
    if(ind==n-1){
        
        long long one=tmp*10+(s[ind]-'0');
        long long two=final+tmp+(s[ind]-'0');

        return one+final==i || two==i;
    }
    bool fa=false;
        
        fa|=f(s,i,tmp*10+(s[ind]-'0'),ind+1,n,final);
        fa|=f(s,i,(s[ind]-'0'),ind+1,n,final+tmp);
        
    
    return fa;

}
bool check(long long sq,long long i){
    bool flag=false;
    string s=to_string(sq);
  
    flag=f(s,i,0,0,s.length(),0);
    return flag;
}
public:
    int punishmentNumber(int n) {
        vector<int>ans(1001,0);
        for(int i=1;i<=n;i++){
            long long sq=i*i;
            if(check(sq,i)){
              
                ans[i]=1;
            }
        }
        long long sm=0;
        for(int i=1;i<=n;i++){
            if(ans[i]==1){
                sm+=pow(i,2);
            }
        }
        return sm;
    }
};