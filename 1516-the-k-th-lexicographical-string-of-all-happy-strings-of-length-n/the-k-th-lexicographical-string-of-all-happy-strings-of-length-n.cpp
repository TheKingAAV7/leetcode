class Solution {
    
private:

void f(int n, vector<string>&st,string &tmp,char prev){
if(tmp.length()==n){
    
        st.push_back(tmp);
        
    
    return;
}

for(char c='a';c<='c';c++){
    if(c!=prev){
    tmp.push_back(c);
    f(n,st,tmp,c);
    tmp.pop_back();
    }

}
return;


}

public:
    string getHappyString(int n, int k) {
        vector<string>st;
        
        string tmp="";

        f(n,st,tmp,'0');
        
        if(k<=st.size()) return st[k-1];
        return "";

    }
};