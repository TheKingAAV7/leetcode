class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==2) {
            ans.push_back(-1);
            }
            else{
                // from right select leftmost 1
                int x= nums[i];
                int b=0;
                while(x>0){
                    if(x&1){
                        x>>=1;
                    }
                    else{
                        break;
                    }
                    b++;
                }

                b--;
                //         6543210
               // cout<<b<<endl;
                int tans= nums[i] ^ (1<<b); // toggle the bit 1->0
                ans.push_back(tans);

            }

            
        }
        return ans;
    }
};