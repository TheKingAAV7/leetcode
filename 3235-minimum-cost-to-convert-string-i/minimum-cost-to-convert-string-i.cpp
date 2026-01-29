class Solution {
public:
#define ll long long
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<array<int,2>>>adj(26);
        int m=cost.size();
        for(int i=0;i<m;i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        
        vector<vector<ll>>dist(26,vector<ll>(26,LLONG_MAX));
        for(int i=0;i<26;i++){
            dist[i][i]=0ll;
            // cst,cur
            
            priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>>pq;
            pq.push({0,i});
            while(!pq.empty()){
                auto cur= pq.top();
                pq.pop();
                ll cst=cur[0];
                ll val=cur[1];
                if(dist[i][val]<cst) continue;
                for(auto it:adj[val]){
                    int nxtval=it[0];
                    int wt=it[1];
                    if(cst+wt<dist[i][nxtval]){
                        dist[i][nxtval]=cst+wt;
                        pq.push({cst+wt,nxtval});
                    }
                }
            }
        }
        int n=source.length();
        ll ans=0;
        for(int i=0;i<n;i++){
            if(source[i]!=target[i]){
                int curval= source[i]-'a';
                int nxtval=target[i]-'a';
                if(dist[curval][nxtval]!=LLONG_MAX) ans+=dist[curval][nxtval];
                else return -1;
            }
        }
        return ans;
    }
};