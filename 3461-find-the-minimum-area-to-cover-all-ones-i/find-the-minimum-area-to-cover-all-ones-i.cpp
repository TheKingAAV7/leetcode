class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int imn,imx,jmn,jmx;
        imn=jmn=1001;
        imx=jmx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                imn=min(i,imn);
                imx=max(i,imx);
                jmn=min(j,jmn);
                jmx=max(j,jmx);
                }
            }
        }
        if(jmx==-1) return 0;
        // cout<<imn<<" "<<imx<<" "<<jmn<<" "<<jmx<<endl;
        // int x1=imn;
        // int y1=jmn;
        // int x2=imx;
        // int y2=jmx;
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        int len=jmx-jmn+1;
        int wid=imx-imn+1;
        return len*wid; 
    }
};