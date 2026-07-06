class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        /*
        (1 4) (2 3)

        */
        int n= arr.size();
        sort(arr.begin(),arr.end(),[&](vector<int>&a,vector<int>&b)->bool{
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int mx=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mx>=arr[i][1]) cnt++;
            mx=max(mx,arr[i][1]);
        }
        return n-cnt;
    }
};