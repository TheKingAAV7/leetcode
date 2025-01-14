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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        vector<double>ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            double sm=0;
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                q.pop();
                sm+=tmp->val;
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
            sm=sm/(1.0*n);
            ans.push_back(sm);
        }
        return ans;
    }
};