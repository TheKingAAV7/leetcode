class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n= nums.size();

        vector<int>ans;

        for(int i=0;i<n;i++){
            int a= nums[i];

            if(a==2){
                ans.push_back(-1);
            }
            else{
                int tmp=-1;
                for(int x=1;x<=a;x++){
                    if((x|(x+1))==a){
                        tmp=x;
                        break;
                    }
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};