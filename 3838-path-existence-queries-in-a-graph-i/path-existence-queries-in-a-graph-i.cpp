class Solution {

public:
    class dsu{
        public:
        vector<int>par,rank;
        dsu(int n){
            par.resize(n,0);
            rank.resize(n,0);
            iota(par.begin(),par.end(),0);
        }
        int findpar(int x){
            if(par[x]==x) return x;
            return par[x]=findpar(par[x]);
        }
        void uni(int x, int y){
            int parx=findpar(x);
            int pary=findpar(y);
            if(parx==pary) return;
            if(rank[parx]>rank[pary]){
                par[y]=x;
            }
            else if(rank[parx]<rank[pary]){
                par[x]=y;
            }
            else{
                par[y]=x;
                rank[x]++;
            }
        }

        bool check(int x, int y){
            int parx=findpar(x);
            int pary=findpar(y);
            return parx==pary;
        }


    };
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        dsu d(n);
        vector<bool>ans;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=maxDiff){
                d.uni(i,i+1);
            }
        }
        for(auto it:queries){
            int x=it[0],y=it[1];
            ans.push_back(d.check(x,y));
        }
        return ans;
    }
};