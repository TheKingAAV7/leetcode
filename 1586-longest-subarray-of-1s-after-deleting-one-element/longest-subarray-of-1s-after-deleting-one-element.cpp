class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int>pref(n,0);
        vector<int>suff(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                cnt=0;
            }
            pref[i]=cnt;

        }
        cnt=0;
        for(int j=n-1;j>=0;j--){
            if(nums[j]==1){
                cnt++;
            }
            else cnt=0;
            suff[j]=cnt;
            
        }
        int ans=0;
        int tmp;
        // for(int i: pref) cout<<i<<" ";
        // cout<<endl;
        // for(int j: suff) cout<<j<<" ";
        // cout<<endl;
        for(int i=1;i<n-1;i++){
            tmp=pref[i-1] + suff[i+1];
            ans=max(ans,tmp);
        }
        ans =max(ans,suff[1]);
        ans=max(ans,pref[n-2]);
        return ans;

    }
};

/*
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,n=nums.size(),curr=0,prev=-1; // setting prev=-1 to handle if there are no 0s
        for(int i=0;i<n;i++){
            if(nums[i]){
                curr++; // just increament current count of 1
            }else{
                // after encountering 0, set prev count to current count and current count to 0
                prev=curr; 
                curr=0;
            }
            ans=max(ans,curr+prev); // update max count of 1s in each iteration
        }
        return ans;
    }
};
*/