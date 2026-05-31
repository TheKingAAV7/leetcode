#define ll long long
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        ll M=mass;
        int pos=0;
        int n= ast.size();
        while(pos<n and M>=ast[pos]) M+=ast[pos++];
        return pos>=n;
    }
};