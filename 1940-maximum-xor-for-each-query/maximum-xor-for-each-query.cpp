class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
      int n=nums.size();
      vector<int>bits(maximumBit,0);
      for(int i=0;i<n;i++){
        for(int j=0;j<maximumBit;j++){
            if((nums[i]>>j)&1){
                bits[maximumBit-j-1]++;
            }
        }
        
      }
      vector<int>ans;
     
      for(int i=0;i<n;i++){
      int deci=0;
      
      for(int j=0;j<maximumBit;j++){
        if(bits[j]%2==0){
            deci= (deci<<1)|1;
        }
        else deci= deci<<1;
      }
      ans.push_back(deci);
        int last = nums.back();
     
        nums.pop_back();
        
        for(int j=0;j<maximumBit;j++){
            bits[maximumBit-j-1]-=((last>>j)&1);
        }

        
      }
      return ans;
    }
};