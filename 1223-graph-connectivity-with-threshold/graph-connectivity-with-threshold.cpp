class Solution {
private:
vector<int>rank,parent;
int find(int node){
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node]);
}
bool unif(int x, int y){
    int parx=find(x);
    int pary=find(y);
    if(parx==pary) return true;
    return false;
}

void uni(int x, int y ){
    int parx=find(x);
    int pary=find(y);
    if(parx==pary) return;
    if(rank[parx]>rank[pary]){
        parent[pary]=parx;
    }
    else if(rank[parx]==rank[pary]){
        parent[pary]=parx;
        rank[parx]++;
    }
    else{
        parent[parx]=pary;
    }
    return;
}
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        parent.resize(n+1);
        rank.resize(n+1);
        vector<bool>ans;
        iota(parent.begin(),parent.end(),0);
        fill(rank.begin(),rank.end(),0);
        for (int d = threshold + 1; d <= n; ++d) {
        for (int m = 2*d; m <= n; m += d) {
            uni(d, m);
        }
    }
        for(auto it:queries){
            int g=gcd(it[0],it[1]);
            
            if(unif(it[0],it[1])){
                ans.push_back(true);
                continue;
            }
            ans.push_back(false);

        }
        return ans;
    }
};