class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int cnt=0;
        for(int j=0;j<m;j++){
            bool inc=true;
            for(int i=1;i<n;i++){
                if(strs[i][j]<strs[i-1][j]){
                    inc=false;
                    break;
                }
            }
            cnt+=(!inc);
        }
        return cnt;
    }
};