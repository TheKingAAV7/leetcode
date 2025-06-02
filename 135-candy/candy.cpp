class Solution {
public:
    int candy(vector<int>& arr) {
       int n=arr.size();
       if(n==1) return 1;
       vector<int>ans(n,0);
       int cnt=0;
       for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1])cnt++;
        else cnt=0;
        ans[i]=max(ans[i],cnt);
       }
       cnt=0;
       for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]) cnt++;
            else cnt=0;
            ans[i]=max(ans[i],cnt);
       } 
       int res=accumulate(ans.begin(),ans.end(),n);
       return res;
    }
};