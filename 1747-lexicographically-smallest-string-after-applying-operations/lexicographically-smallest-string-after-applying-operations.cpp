class Solution {
public:
    
    
    string findLexSmallestString(string s, int a, int b) {
        string ans=s;
        set<string>vis;
        function<string(string)>roto=[&](string cur){
            reverse(cur.begin(),cur.end());  //abcde  -> cdeab
            reverse(cur.begin(),cur.begin()+b);
            reverse(cur.begin()+b,cur.end());
            return cur;
        };
        function<string(string)>add=[&](string cur){
            for(int i=1;i<cur.size();i+=2){
                int tmp=cur[i]-'0';
                tmp=tmp+a;
                cur[i]=(tmp%10)+'0';
            }
            return cur;
        };
        function<void(string )>dfs=[&](string node){
            if(vis.find(node)!=vis.end()) return;
            ans=min(ans,node);
            vis.insert(node);
            string s1=roto(node);
            dfs(s1);
            string s2=add(node);
            dfs(s2);
            
            return;
        };
        dfs(s);
        return ans;
    }
};