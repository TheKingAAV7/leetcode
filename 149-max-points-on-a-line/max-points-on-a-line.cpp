class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        /*
        first consider two points

        calculate the equation
        
        (x-x1)/(y-y1)=(x2-x1)/(y2-y1)           confirmed.
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
        
        for(int i=0;i<n;i++){
            unordered_map<double,int>mp;
            for(int j=i+1;j<n;j++){
                double x1=pts[i][0];
                double y1=pts[i][1];
                double x2=pts[j][0];
                double y2=pts[j][1];
                if(y2!=y1){
                    double slope=(x2-x1)/(y2-y1);
                    mp[slope]++;
                }
            } 
            for(auto it:mp) ans=max(ans,it.second+1);
        }
        
        return ans;
        
    }
};