class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obst) {
        /*

        LOGIN
        */
        int ans=0;
        bool ins=false;
        map<int,set<int>>row,col;
        bool zobs=false;
        for(auto it:obst){
            if(it[0]==0 and it[1]==0){
            zobs=true;
            continue;
            }
            row[it[0]].insert(it[1]);
            col[it[1]].insert(it[0]);
            
        }
        // for(auto &it:row){
        //     sort(it.second.begin(),it.second.end());
        // }
        // for(auto &it:col){
        //     sort(it.second.begin(),it.second.end());
        // }
        vector<array<int,2>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int cur=0;

        int x=0, y=0;
        for(auto i:commands){
            if(i==-1){
                cur=(cur+1)%4;
            }
            else if(i==-2){
                cur=(cur-1+4)%4;
            }
            else{
                int nx=x+dir[cur][0]*i;
                int ny=y+dir[cur][1]*i;
                if(cur%2==0){
                    // check in row
                    auto it= row[nx].lower_bound(min(y,ny));
                    if(it==row[nx].end()){
                        x=nx;
                        y=ny;
                    }
                    else{
                        int val= *it;
                        if(val>=min(y,ny) and val<=max(y,ny)){
                            x=nx;
                            y=val;
                            if(cur==0) y--;
                            else y++;
                        }
                        else{
                         x=nx;
                         y=ny;
                        }
                    }
                }
                else{
                    // check in col
                    auto it= col[ny].lower_bound(min(x,nx));
                    if(it==col[ny].end()){
                        x=nx;
                        y=ny;
                    }
                    else{
                        int val= *it;
                        if(val>=min(x,nx) and val<=max(x,nx)){
                            x=val;
                            y=ny;
                            if(cur==1) x--;
                            else x++;
                        }
                        else{
                         x=nx;
                         y=ny;
                        }
                    }
                }

                if(!ins){
                    if(zobs){
                        row[0].insert(0);
                        col[0].insert(0);
                    }
                    ins=true;
                }
                
            }
            // cout<<x<<" "<<y<<endl;
            ans= max(ans,abs(x*x)+abs(y*y));
        }

        return ans;

    }
};