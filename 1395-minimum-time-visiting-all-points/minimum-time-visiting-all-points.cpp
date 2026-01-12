class Solution {
public:

 /*

 two points can be in the same row, or col..
 or diagonally opposite ...


 */
    int minTimeToVisitAllPoints(vector<vector<int>>& pts) {
        int ans=0;
        int n=pts.size();
        vector<int>ro={1,-1,0,0,1,-1,-1,1};
        vector<int>col={0,0,1,-1,1,1,-1,-1};
        auto f=[&](int x, int y, int rx, int ry)->int{

            queue<array<int,3>>q;
            q.push({0,x,y});
            while(!q.empty()){
                auto cur= q.front();
                q.pop();
                int dis= cur[0];
                int curx= cur[1];
                int cury= cur[2];
                if(curx== rx and cury==ry) return dis;
                for(int k=0;k<8;k++){
                    int nx= curx+ro[k];
                    int ny= cury+col[k];
                    if(nx>=-1000 and nx<=1000 and ny>=-1000 and ny<=1000){
                        q.push({dis+1,nx,ny});
                    }
                }

            }
            return -1;

        };
        for(int i=1;i<n;i++){
            int x= pts[i-1][0];
            int y= pts[i-1][1];

            int rx= pts[i][0];
            int ry= pts[i][1];
         
            ans+=max(abs(x-rx),abs(y-ry));
        }
        return  ans;

    }
};