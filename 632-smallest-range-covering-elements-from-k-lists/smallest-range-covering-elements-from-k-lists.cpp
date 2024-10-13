#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Optimize I/O operations
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Min-heap (priority queue) to store the current smallest element from each list
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int maxi = INT_MIN;
        int n = nums.size();
        vector<int> pos(n, 0);  // Track current positions of each list
        
        // Insert the first element of each list into the heap
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i][0], i});
            maxi = max(maxi, nums[i][0]);
        }
        
        int left = 0, right = INT_MAX;
        
        // Process the heap
        while (true) {
            auto [elef, gp] = pq.top();  // Get the smallest element and its group index
            pq.pop();
            
            // Update the smallest range if necessary
            if (maxi - elef < right - left) {
                left = elef;
                right = maxi;
            }
            
            // Move to the next element in the current group
            if (++pos[gp] < nums[gp].size()) {
                int next_val = nums[gp][pos[gp]];
                pq.push({next_val, gp});
                maxi = max(maxi, next_val);  // Update the maximum element
            } else {
                // If one of the lists is exhausted, we stop
                break;
            }
        }
        
        return {left, right};
    }
};
