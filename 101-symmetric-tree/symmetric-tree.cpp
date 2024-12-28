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
bool f(TreeNode* r1,TreeNode* r2){
    if(!r1 and !r2) return true;
    if(!r1 || !r2) return false;
    if(r1->val!=r2->val) return false;
    bool a=f(r1->left,r2->right);
    bool b= f(r1->right,r2->left);
    return a and b;
}
public:
    bool isSymmetric(TreeNode* root) {
        return f(root->left,root->right);
    }
};