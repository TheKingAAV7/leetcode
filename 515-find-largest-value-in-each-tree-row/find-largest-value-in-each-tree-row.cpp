/**
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int n=q.size();
            int maxi=INT_MIN;
            while(n--){
                TreeNode* tmp=q.front();
                q.pop();
                maxi=max(maxi,tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
                
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};