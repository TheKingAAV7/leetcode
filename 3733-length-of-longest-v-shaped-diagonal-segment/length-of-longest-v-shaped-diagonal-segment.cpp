class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(4,0)));
       
       // leftup (-1 -1)
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                int ni=i-1;
                int nj=j-1;
                if(ni>=0 and nj>=0 and grid[ni][nj]==2) dp[i][j][0]=1+dp[ni][nj][0];
                else dp[i][j][0]=1;
            }
            else if(grid[i][j]==2){
                int ni=i-1;
                int nj=j-1;
                if(ni>=0 and nj>=0 and grid[ni][nj]==0) dp[i][j][0]=1+dp[ni][nj][0];
                else dp[i][j][0]=1;
            }
            else dp[i][j][0]=0;
        }

       }

       // rigup (-1,1)
       for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(grid[i][j]==0){
                int ni=i-1;
                int nj=j+1;
                if(ni>=0 and nj<m and grid[ni][nj]==2) dp[i][j][1]=1+dp[ni][nj][1];
                else dp[i][j][1]=1;
            }
            else if(grid[i][j]==2){
                int ni=i-1;
                int nj=j+1;
                if(ni>=0 and nj<m and grid[ni][nj]==0) dp[i][j][1]=1+dp[ni][nj][1];
                else dp[i][j][1]=1;
            }
            else dp[i][j][1]=0;
        }

       }

       // lefd (+1,-1)
         for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                int ni=i+1;
                int nj=j-1;
                if(ni<n and nj>=0 and grid[ni][nj]==2) dp[i][j][2]=1+dp[ni][nj][2];
                else dp[i][j][2]=1;
            }
            else if(grid[i][j]==2){
                int ni=i+1;
                int nj=j-1;
                if(ni<n and nj>=0 and grid[ni][nj]==0) dp[i][j][2]=1+dp[ni][nj][2];
                else dp[i][j][2]=1;
            }
            else dp[i][j][2]=0;
        }

       }

       // rd(+1 +1)

   for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(grid[i][j]==0){
                int ni=i+1;
                int nj=j+1;
                if(ni<n and nj<m and grid[ni][nj]==2) dp[i][j][3]=1+dp[ni][nj][3];
                else dp[i][j][3]=1;
            }
            else if(grid[i][j]==2){
                int ni=i+1;
                int nj=j+1;
                if(ni<n and nj<m and grid[ni][nj]==0) dp[i][j][3]=1+dp[ni][nj][3];
                else dp[i][j][3]=1;
            }
            else dp[i][j][3]=0;
        }

       }


       /*

        0-> lup
        1-> rup
        2-> ld
        3-> rd

       */
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                        // lup i-1,j+1,i+1,j-1
                        int i1=i-1;
                        int j1=j-1;
                        int lup=1;
                        int req=2;
                        bool f=false;
                        
                        while(i1>=0 and j1>=0){
                         
                            if(grid[i1][j1]==req){
                                f=true;
                                req=(req==2)?0:2;
                                lup++;
                                   if(f){
                                int ni1=i1-1;
                                int nj1=j1+1;
                                if(ni1>=0 and nj1<m and grid[ni1][nj1]==req){
                                    ans=max(ans,lup+dp[ni1][nj1][1]);
                                }
                                // int ni2=i1+1;
                                // int nj2=j1-1;
                                // if(ni2<n and nj2>=0 and grid[ni2][nj2]==req){
                                //     ans=max(ans,lup+dp[ni2][nj2][2]);
                                // }
                            }
                            }
                            else break;
                            
                            i1--;
                            j1--;
                        }
                        ans=max(ans,lup);

                        //rup
                        int rup=1;
                        i1=i-1;
                        j1=j+1;

                         req=2;
                         f=false;
                        
                        while(i1>=0 and j1<m){
                           
                            if(grid[i1][j1]==req){
                                f=true;
                                req=(req==2)?0:2;
                                rup++;
                                 if(f){
                                int ni1=i1+1;
                                int nj1=j1+1;
                                if(ni1<n and nj1<m and grid[ni1][nj1]==req){
                                    ans=max(ans,rup+dp[ni1][nj1][3]);
                                }
                                // int ni2=i1-1;
                                // int nj2=j1-1;
                                // if(ni2>=0 and nj2>=0 and grid[ni2][nj2]==req){
                                //     ans=max(ans,rup+dp[ni2][nj2][0]);
                                // }
                            }
                            }
                            else break;
                            
                            i1--;
                            j1++;
                        }
                        ans=max(ans,rup);

                        //ld
                        int ld=1;
                        i1=i+1;
                        j1=j-1;

                         req=2;
                         f=false;
                        
                        while(i1<n and j1>=0){
                           
                            if(grid[i1][j1]==req){
                                f=true;
                                req=(req==2)?0:2;
                                ld++;
                                 if(f){
                                // int ni1=i1+1;
                                // int nj1=j1+1;
                                // if(ni1<n and nj1<m and grid[ni1][nj1]==req){
                                //     ans=max(ans,ld+dp[ni1][nj1][3]);
                                // }
                                int ni2=i1-1;
                                int nj2=j1-1;
                                if(ni2>=0 and nj2>=0 and grid[ni2][nj2]==req){
                                    ans=max(ans,ld+dp[ni2][nj2][0]);
                                }
                            }
                            }
                            else break;
                            
                            i1++;
                            j1--;
                        }
                        ans=max(ans,ld);

                        // rd
                        int rd=1;
                        i1=i+1;
                        j1=j+1;

                         req=2;
                         f=false;
                        
                        while(i1<n and j1<m){
                           
                            if(grid[i1][j1]==req){
                                f=true;
                                req=(req==2)?0:2;
                                rd++;
                                if(f){
                               
                                // int ni1=i1-1;
                                // int nj1=j1+1;
                                // if(ni1>=0 and nj1<m and grid[ni1][nj1]==req){
                                //     ans=max(ans,rd+dp[ni1][nj1][1]);
                                // }
                                int ni2=i1+1;
                                int nj2=j1-1;
                                
                                if(ni2<n and nj2>=0 and grid[ni2][nj2]==req){
                                    ans=max(ans,rd+dp[ni2][nj2][2]);
                                }
                            }
                            }
                            else break;
                            
                            i1++;
                            j1++;
                        }
                        ans=max(ans,rd); 
                        if(ans==3) cout<<i<<" "<<j<<endl; 
                        //cout<<ld<<" "<<rd<<" "<<lup<<" "<<rup<<endl; 
                        
                }
            }
        }





        return ans;
        
    }
};