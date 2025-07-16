class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int od=0,ev=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        int ans =0;
        for(int p=0;p<2;p++){
            for(int q=0;q<2;q++){
                int pos=0;
                int cnt=1;
                while(pos<n and nums[pos]!=p) pos++;
                if(pos==n) {
                    continue;
                }
                bool second=true;
                for(int i=pos+1;i<n;i++){
                    if(second){
                        if(nums[i]==q){
                            cnt++;
                            second=!second;
                        } 
                        
                    }
                    else{
                        if(nums[i]==p){
                            cnt++;
                            second=!second;
                        }
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};