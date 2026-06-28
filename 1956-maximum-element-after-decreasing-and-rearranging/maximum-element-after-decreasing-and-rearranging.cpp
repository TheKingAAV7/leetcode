class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n= arr.size();
        arr[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                arr[i]=arr[i-1]+1;
                ans=max(ans,arr[i]);
            }
            else{
                if(arr[i]>arr[i-1])
                arr[i-1]=arr[i]+1;
                else arr[i-1]=arr[i];
                ans=max(ans,arr[i-1]);
            }
        }
        return ans;
    }
};