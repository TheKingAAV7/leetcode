class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        sort(meet.begin(),meet.end());
        int n=meet.size();
        int ans=0;
        if(meet[0][0]>1) ans+=(meet[0][0]-1);
        int end=meet[0][1];
        for(int i=1;i<n;i++){
            if(meet[i][0]>end){
                ans+=(meet[i][0]-end-1);
            }
            end=max(end,meet[i][1]);
        }
        ans+=(days-end);
        return ans;
    }
};