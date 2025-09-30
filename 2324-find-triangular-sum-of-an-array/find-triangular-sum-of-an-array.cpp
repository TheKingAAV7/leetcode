class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prev=nums;
        for(int i=0;i<n-1;i++){
            vector<int>cur;
            for(int j=0;j<prev.size()-1;j++){
                cur.push_back((prev[j]+prev[j+1])%10);
            }
            // for(int l:cur) cout<<l<<" ";
            // cout<<endl;
            prev=cur;
        }
        return prev[0];
    }
};