class Solution {
public:
    long long calculateScore(vector<string>& ins, vector<int>& values) {
        int n=values.size();
        vector<int>vis(n,0);
        long long score=0;
        int pos=0;
        while(true){
            if(pos<0 || pos>=n || vis[pos]) break;
            if(ins[pos]=="add"){
                vis[pos]=1;
                score+=values[pos];
                pos++;
                
            }
            else{
               vis[pos]=1;
                pos=pos+values[pos];
            }
        }
        return score;
    }
};