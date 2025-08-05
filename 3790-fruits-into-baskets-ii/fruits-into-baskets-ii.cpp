class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fts, vector<int>& bkt) {
        int n=fts.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(bkt[j]>=fts[i]){
                    bkt[j]=0;
                    cnt++;
                    break;
                }
            }
        }
        return n-cnt;
        
    }
};