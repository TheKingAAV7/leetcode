class Solution { /// 11100

public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        // 0 1 1 1 0 0  1 0 0 1 0 0
        int n= nums.size();
        for(int i=0;i<nums.size();i++){
            while(i<n and nums[i]==1 ) i++;
            if(i>=n) break;
            
            if(n-i<3) return -1;
            
            cnt++;
            for(int j=0;j<3;j++){
                nums[i+j]= !nums[i+j];
               
            }
            //  for(auto it: nums) cout<<it<<" ";
            //     cout<<endl;

        }
        return cnt;
    }
};
//1 1 1 0 0 0