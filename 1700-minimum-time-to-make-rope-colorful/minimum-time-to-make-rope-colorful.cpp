class Solution {
public:
    int minCost(string col, vector<int>& arr) {

        int ans=0;
        int cnt=0;
        int n=col.length();
        int maxi=0;
        char prev='.';
        for(int i=0 ;i<n;i++){
            if(col[i]!=prev){
               
                ans+=maxi;
                prev=col[i];
                cnt=1;
                maxi=arr[i];
            }
            else{
                cnt++;
                maxi=max(maxi,arr[i]);
            }
        }
        ans+=maxi;

        int total= accumulate(arr.begin(),arr.end(),0);
        return total-ans;
        
    }
};