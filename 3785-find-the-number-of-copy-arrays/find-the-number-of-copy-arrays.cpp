class Solution {
public:
    int countArrays(vector<int>& arr, vector<vector<int>>& bounds) {
        vector<int>diff;
        int n=arr.size();
        for(int i=1;i<n;i++){
            diff.push_back(arr[i]-arr[i-1]);
        }
        int ans=INT_MAX;
        int l=bounds[0][0],h=bounds[0][1];
        ans=min(ans,h-l+1);
        int pos=0;
        int el=l+diff[pos],eh=h+diff[pos];
        pos++;
        for(int i=1;i<n;i++){
            int low=bounds[i][0],high=bounds[i][1];
            if(high<el || low>eh) return 0;
            low=max(low,el);
            high=min(high,eh);
            ans=min(ans,high-low+1);
            if(pos==n-1) break;
            el=low+diff[pos];
            eh=high+diff[pos];
            pos++;
        }
        return ans;
        
    }
};