class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        long long ans=arr.back();
        int i=1;
        --k;
        while(k--){
            ans+=max((arr[n-i-1] - i),0);
            i++;
        }
        return ans;
    }
};