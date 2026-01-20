class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==2) ans.push_back(-1);
            else{
                // from right select leftmost 1
                int x= nums[i];
                int b=0;
                while(x>0){
                    if(x%2==1){
                        x>>=1;
                    }
                    else{
                        break;
                    }
                    b++;
                }
                b--;
               // cout<<b<<endl;
                int tans= nums[i] ^ (1<<b);
                ans.push_back(tans);

            }

            
        }
        return ans;
    }
};