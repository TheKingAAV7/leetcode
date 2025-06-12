class Solution {
private:
vector<int>parent,rank;

int findpar(int u){
    if(parent[u]==u) return u;

    return parent[u]=findpar(parent[u]);
}

void uni(int u, int v){
    int paru=findpar(u);
    int parv=findpar(v);
    if(paru==parv) return;
    if(rank[paru]<rank[parv]){
        parent[paru]=parv;
    }
    else if(rank[paru]==rank[parv]){
        parent[paru]=parv;
        rank[paru]++;
    }
    else{
        parent[parv]=paru;
    }
    return;
}
public:
    int numberOfComponents(vector<vector<int>>& p, int k) {
        int n=p.size();
        parent.resize(n,0);
        rank.resize(n,0);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<n;i++){
            set<int>st;
            for(int l:p[i])  st.insert(l);
            for(int j=i+1;j<n;j++){
                int cnt=0;
                for(int l:p[j]){
                    if(st.find(l)!=st.end()){
                        cnt++;
                        st.erase(l);
                    }
                }
                if(cnt>=k) uni(i,j);
                for(int l:p[i])  st.insert(l);

            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) ans++;
        }
        return ans;

    }
};