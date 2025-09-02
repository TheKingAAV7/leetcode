class Solution {
public:
    int numberOfPairs(vector<vector<int>>& pts) {
        sort(pts.begin(),pts.end(),[&](vector<int>&a,vector<int>&b)->bool{
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>=b[1];
        });
        for(auto it:pts) cout<<it[0]<<" "<<it[1]<<endl;
        int n=pts.size();
        int ans=0;
        for(int i=1;i<n;i++){
            int x=INT_MIN,y=INT_MIN;
            for(int j=i-1;j>=0;j--){
                int x1=pts[j][0];
                int y1=pts[j][1];
                int x2=pts[i][0];
                int y2=pts[i][1];
                if(x1<=x2 and y1>=y2 ){
                bool possi=true;
                for(int k=0;k<i;k++){
                    if(k!=j){
                    int x=pts[k][0];
                    int y=pts[k][1];
                    if(x>=x1 and x<=x2 and y>=y2 and y<=y1){
                        possi=false;
                        break;
                    }
                    }
                }
              //  
                if(possi){
                   // cout<<j<<" "<<i<<endl;
                 ans+=1;
                }
                }
            }
        }
        return ans;
    }
};