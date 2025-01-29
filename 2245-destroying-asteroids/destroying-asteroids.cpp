class Solution {
public:
    bool asteroidsDestroyed(int ma, vector<int>& ast) {
        int n=ast.size();
        long long mass=ma;
        sort(ast.begin(),ast.end());
        for(int i=0;i<n;i++){
            if(mass>=ast[i]){
                mass+=ast[i];
            }
            else return false;
        }
        return true;
        
    }
};