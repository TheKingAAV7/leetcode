class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        /*
        first consider two points

        calculate the equation
        
        (x-x1)/(x2-x1)=(y-y1)/(y2-y1)           confirmed.
        we have x1, y1, x2,y2, now just put x3 and y3 in above equation and count

        (x-2)=(y-3)/(0)
        */
        
        int ans=0;
        map<int,int>row,col;
        for(auto it:pts){
            row[it[0]]++;
            col[it[1]]++;
            ans=max({ans,row[it[0]],col[it[1]]});
        }
        int n=pts.size();
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double x1=pts[i][0];
                double y1=pts[i][1];
                double x2=pts[j][0];
                double y2=pts[j][1];
               
                int cnt=2;
                for(int k=j+1;k<n;k++){
                    double x3=pts[k][0];
                    double y3=pts[k][1];
                    if((x2-x1)!=0 and (y2-y1)!=0){
                    double lef=(x3-x1)/(x2-x1);
                    double rig=(y3-y1)/(y2-y1);
                    if(lef==rig) cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
        
    }
};