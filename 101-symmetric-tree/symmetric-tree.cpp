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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>ans;
            while(n--){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left){
                    q.push(tmp->left);
                    ans.push_back(tmp->left->val);
                }
                if(!tmp->left) ans.push_back(-101);
                if(tmp->right){
                    q.push(tmp->right);
                    ans.push_back(tmp->right->val);
                }
                if(!tmp->right) ans.push_back(-101);

            }
            vector<int>tmp=ans;
            reverse(tmp.begin(),tmp.end());
            if(tmp!=ans) return false;
        }
        return true;

    }
};