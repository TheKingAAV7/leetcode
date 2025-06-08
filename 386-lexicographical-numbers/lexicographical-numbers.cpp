class Solution {
private:
void f(int n,vector<int>&ans,string& tmp,int len){

if(len>=0){
    if(tmp!=""){
    int num=stoi(tmp);
    if(num<=n) ans.push_back(num);
    else return;
    }
}
else return;
if(tmp==""){
for(char c='1';c<='9';c++){
    tmp.push_back(c);
    f(n,ans,tmp,len-1);
    tmp.pop_back();
}
}
else{
    for(char c='0';c<='9';c++){
        tmp.push_back(c);
        f(n,ans,tmp,len-1);
        tmp.pop_back();
    }
}
return;
}

public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        string num=to_string(n);
        int len=num.size();
        string tmp="";
        f(n,ans,tmp,len);
        return ans;
    }
};