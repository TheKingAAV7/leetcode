/** 7 6 8 5   
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int minimumOperations(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int ans1 = 0;

    while (!q.empty()) {
        int n = q.size();
        vector<pair<int, int>> ans; // {value, original index}
        int pos = 0;

        while (n--) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
                ans.push_back({tmp->left->val, pos++});
            }
            if (tmp->right) {
                q.push(tmp->right);
                ans.push_back({tmp->right->val, pos++});
            }
        }

        // Sort the array and calculate minimum swaps
        vector<bool> visited(ans.size(), false);
        sort(ans.begin(), ans.end()); // Sort by values
        int swaps = 0;

        for (int i = 0; i < ans.size(); ++i) {
            if (visited[i] || ans[i].second == i) continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = ans[j].second;
                cycle_size++;
            }

            if (cycle_size > 1) swaps += cycle_size - 1;
        }

        ans1 += swaps;
    }

    return ans1;
}

};