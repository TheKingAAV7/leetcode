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
    bool f(TreeNode* root, TreeNode* cur){
        if(!root and !cur) return true;
        if(!root || !cur) return false;
        
        if(root->val==cur->val) return f(root->left, cur->left) and f(root->right,cur->right);
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      bool ans=false;
      if(!root) return false;
      if(root->val==subRoot->val){
        ans|=f(root->left,subRoot->left) and f(root->right,subRoot->right);
      }
      ans|=isSubtree(root->left,subRoot);
      ans|=isSubtree(root->right,subRoot);
      return ans;
    }
};