class Solution {
private: 
void f(string tmp, vector<int>&ans, int n){
if(stoi(tmp)>n) return ;
ans.push_back(stoi(tmp));

for(char c='0'; c<='9';c++){
    string s= tmp+c;
    //cout<<s<<endl;
    if(stoi(s)<=n){
        f(s, ans, n);
    }
    else break;
}
return ;

}
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        
        for(char a='1' ; a<='9'; a++){
            string tmp="";
            tmp+=a;
            int curr= stoi(tmp);
            if(curr<=n){
                
                
                f(tmp, ans, n);
            }
           
        }
        return ans;
    }
};