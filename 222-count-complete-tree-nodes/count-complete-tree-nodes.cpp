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
private:
int f(TreeNode *root){
    if(!root) return 0;
    int a=f(root->left);
    int b=f(root->right);
    return a+b+1;
}
public:
    int countNodes(TreeNode* root) {
        
        return f(root);
        
    }
};