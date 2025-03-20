class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x == parent_y) return;
        
        if (rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        }
        else if (rank[parent_y] < rank[parent_x]) {
            parent[parent_y] = parent_x;
        }
        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    
    // Removed dfs function because DSU alone is enough

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        // Union all edges to form connected components.
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            Union(u, v);
        }
        
        // For weights <= 10^5, we can use 18 bits (all ones) as the initial mask.
        const int ALL_ONES = (1 << 18) - 1;
        // For each component representative, store the AND of all edge weights in that component.
        vector<int> compCost(n, ALL_ONES);
        
        // Update the mask for each component using each edge.
        for (auto &edge : edges) {
            int u = edge[0], w = edge[2];
            int comp = find(u);
            compCost[comp] &= w;
        }
        
        int q = query.size();
        vector<int> result(q, -1);
        
        // Answer each query:
        // If s and t are in the same component, return that component's mask; otherwise, return -1.
        for (int i = 0; i < q; i++) {
            int s = query[i][0], t = query[i][1];
            if (find(s) != find(t))
                result[i] = -1;
            else
                result[i] = compCost[find(s)];
        }
        
        return result;
    }
};
