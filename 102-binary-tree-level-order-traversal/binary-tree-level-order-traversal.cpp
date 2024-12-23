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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        ans.push_back({root->val});
        while(!q.empty()){
            int n=q.size();
            vector<int>tmp;
            while(n--){
                TreeNode* l=q.front();
                q.pop();
                if(l->left){
                    q.push(l->left);
                    tmp.push_back(l->left->val);
                }
                 if(l->right){
                    q.push(l->right);
                    tmp.push_back(l->right->val);
                }
            }
            if(tmp.size())
            ans.push_back(tmp);
        }
        return ans;
    }
};