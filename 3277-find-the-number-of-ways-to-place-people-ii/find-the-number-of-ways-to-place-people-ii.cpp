class Solution {
public:
    int numberOfPairs(vector<vector<int>>& pts) {
            sort(pts.begin(),pts.end(),[&](vector<int>&a,vector<int>&b)->bool{
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>=b[1];
        });
        //for(auto it:pts) cout<<it[0]<<" "<<it[1]<<endl;
        int n=pts.size();
        int ans=0;
        for(int i=1;i<n;i++){
            int x=INT_MAX,y=INT_MAX;
            for(int j=i-1;j>=0;j--){
                int x1=pts[j][0];
                int y1=pts[j][1];
                int x2=pts[i][0];
                int y2=pts[i][1];
                if(x1<=x2 and y1>=y2 ){
                if(x1<x and y1<y){
                    x=x1;
                    y=y1;
                    ans++;
                }
                
                }
            }
        }
        return ans;
    }
};