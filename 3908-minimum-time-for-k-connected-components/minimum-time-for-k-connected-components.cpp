class DSU {
private:
    vector<int> parent, rank; // or use size instead of rank
    int sz;
public:
    // Constructor: initialize n nodes (0-based indexing)
    DSU(int n) {
        sz=n;
        parent.resize(n);
        rank.resize(n, 0); // or size.resize(n, 1) if using size
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false; // already in same set

        // attach smaller rank tree under larger
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }

    // Optional: check if two nodes are in same set
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int cntpar(){
        int cnt=0;
        for(int i=0;i<sz;i++){
            if(parent[i]==i) cnt++;
        }
        return cnt;
    }
};


class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int maxi=0;
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b)->bool{
            return a[2]<b[2];
        });
        if(edges.size()==0) return 0;
        for(auto it:edges) maxi=max(maxi,it[2]);
        
        int lo=0,hi=maxi;
        int ans=hi;
        auto f=[&](int tim)->bool{
            DSU d(n);
            for(int i=edges.size()-1;i>=0;i--){
                if(edges[i][2]>tim) d.unite(edges[i][0],edges[i][1]);
                else break;
            }
            return d.cntpar()>=k;

        };
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
               hi = mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};