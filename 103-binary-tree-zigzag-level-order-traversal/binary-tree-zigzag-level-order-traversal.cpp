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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            vector<int>tmp;
            int n=q.size();
            
            for(int i=0;i<n;i++){
            TreeNode* tmp1=q.front();
            q.pop();
            tmp.push_back(tmp1->val);
            if(tmp1->left) q.push(tmp1->left);
            if(tmp1->right)q.push(tmp1->right);
            }
            ans.push_back(tmp);
        }
        for(int i=0;i<ans.size();i++){
            if(i&1) reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};