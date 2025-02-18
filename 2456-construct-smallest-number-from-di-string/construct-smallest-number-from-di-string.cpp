class Solution {
private:
void f(int i,string &pattern,string &ans, string &tmp,int prev,int n,set<char>&st){
    if(tmp.length()==n+1){
        if(ans.empty() || ans>tmp) ans=tmp;
      //cout<<tmp<<endl;
        return;
    }
    if(prev==-1){
        for(char c='1';c<='9';c++){
            tmp.push_back(c);
            st.insert(c);
            f(i,pattern,ans,tmp,c-'0',n,st);
            st.erase(c);
            tmp.pop_back();
           
        }
    }
    else{
        
        char p=prev+'0';
        if(pattern[i]=='I'){
            
            for(char c=p+1;c<='9';c++){
            if(st.find(c)==st.end()){
            tmp.push_back(c);
            st.insert(c);
            f(i+1,pattern,ans,tmp,c-'0',n,st);
            st.erase(c);
            tmp.pop_back();
            }
            }
            
        }
        else{
            
            for(char c=p-1;c>='1';c--){
            if(st.find(c)==st.end()){
            tmp.push_back(c);
            st.insert(c);
            f(i+1,pattern,ans,tmp,c-'0',n,st);
            st.erase(c);
            tmp.pop_back();
            }
            }
            
        }
    }
    return ;
}
public:
    string smallestNumber(string pattern) {
        string ans="";
        string tmp="";
        set<char>st;
        int n=pattern.length();
        

        f(0,pattern,ans,tmp,-1,n,st);
        return ans;
    }
};