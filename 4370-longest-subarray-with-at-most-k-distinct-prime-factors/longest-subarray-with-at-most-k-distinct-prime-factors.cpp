class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n= nums.size();
        int l=0;
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            
            int x= nums[i];
            bool prime=true;
            for(int j=2;j*j<=nums[i];j++){
                while(x%j==0){
                    prime=false;
                    mp[j]++;
                    x/=j;
                }
            }
            if(x>1) mp[x]++;
            // if(prime==true) mp[nums[i]]++;
            // if(i==0) {
            //     for(auto it:mp) cout<<it.first<<"->"<<it.second<<endl;
            // }
            // cout<<endl;
            while((int)(mp.size())>k){
            int x1= nums[l];
            bool prime1=true;
            for(int j=2;j*j<=nums[l];j++){
                while(x1%j==0){
                    prime1=false;
                    mp[j]--;
                    if(mp[j]==0) mp.erase(j);
                    x1/=j;
                }
            }
            if(x1>1){
             mp[x1]--;
             if(mp[x1]==0) mp.erase(x1);
            }
            l++;
            }

            ans=max(ans,i-l+1);
        }
        return ans;
    }
};