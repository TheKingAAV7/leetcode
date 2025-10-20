class Solution {
public:
    int finalValueAfterOperations(vector<string>& ops) {
        int x=0;
        for(auto &it:ops){
            if(it[0]=='+' || it[2]=='+') x++;
            else x--;
        }
        return x;
    }
};