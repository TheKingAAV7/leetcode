class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int>mp;
        int mod=1e9+7;
        int n=arr.size();
        long long ans=0;
        mp[arr[0]]++;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans= (ans+ mp[target-arr[j]-arr[k]] ) %mod;
            }
            mp[arr[j]]++;
        }
    
        return ans;
    }
};