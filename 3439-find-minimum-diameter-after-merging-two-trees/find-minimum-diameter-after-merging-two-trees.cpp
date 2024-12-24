class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        map<int,vector<int>>mp1,mp2;
        for(auto it:edges1){
            mp1[it[0]].push_back(it[1]);
            mp1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
             mp2[it[0]].push_back(it[1]);
            mp2[it[1]].push_back(it[0]);
        }


        auto dfs =[&](auto &self,int node, map<int,vector<int>>&mp,int &maxi,vector<int>&vis,int cnt)->int{
            if(vis[node]==1) return 0;
            vis[node]=1;
            priority_queue<int>pq;
            pq.push(0);
            
            for(auto it:mp[node]){
                if(vis[it]==0){
                    int tmp=self(self,it,mp,maxi,vis,cnt);
                    pq.push(tmp);
                }
            }
           // if(pq.size()==1) return 1;
            int t=pq.top();
            pq.pop();
            int s = pq.empty() ? 0 : pq.top();
            maxi = max(maxi, t+s);
            return t+1;
        };
        int m=mp2.size();
        int n=mp1.size();
        vector<int>vis1(n,0),vis2(m,0);
        int maxi1=0,maxi2=0;
        if(mp1.size()==0 || mp2.size()==0){
            if(mp1.size()==0 and mp2.size()==0) return 1;
            if(mp1.size()==0){
                dfs(dfs,0,mp2,maxi2,vis2,0);
                return ceil((1.0*maxi2)/2.0)+1;
            }
            dfs(dfs,0,mp1,maxi1,vis1,0);
                return ceil((1.0*maxi1)/2.0)+1;

        }
        int ans1=0;
        int ans2=0;
        dfs(dfs,0,mp1,maxi1,vis1,0);
        dfs(dfs,0,mp2,maxi2,vis2,0);
        cout<<maxi1<<" "<<maxi2<<endl;
        return max({maxi1, maxi2, (int)(ceil(maxi1 / 2.0) + ceil(maxi2 / 2.0) + 1)});
        
     
    }
};