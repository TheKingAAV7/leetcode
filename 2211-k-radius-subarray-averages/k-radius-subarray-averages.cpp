class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int K) {
        if(K==0) return nums;
        int k=2*K+1;
        int n=nums.size();
        cout<<n<<endl;
        if(k>n){
            vector<int>ans(n,-1);
            return ans;
        }
        
        
        unordered_map<int, int>mp;
        long long sm=0;
        int pos=K;
        for(int i=0;i<k;i++){
            sm+=nums[i];
        }
        mp[pos]=sm/k;
        pos++;
        vector<int>ans(n,-1);
        int i=0;
        for(int j=k;j<n;j++){
            sm-=nums[i++];
            sm+=nums[j];
            mp[pos++]=sm/k;
        }

        for(int i=0;i<n;i++){
            if(mp.find(i)!=mp.end()){
                ans[i]=mp[i];
            }
        }
        return ans;


        

    }
};