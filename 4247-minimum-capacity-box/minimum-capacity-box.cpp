class Solution {
public:
    int minimumIndex(vector<int>& cap, int itemSize) {
        int n=cap.size();
        int mini=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(cap[i]>=itemSize){
                if(cap[i]<mini){
                    mini=cap[i];
                    idx=i;
                }
            }
        }
        return idx;
    }
};