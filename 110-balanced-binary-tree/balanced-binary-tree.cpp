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
bool ans=true;
    int f(TreeNode* root){
        if(!root) return 0;
        if(!root->left and !root->right){
            return 1;
        }
        int lefht=0,rigght=0;
        if(root->left!=NULL) lefht= f(root->left);
        if(root->right!=NULL) rigght=f(root->right);

        if(abs(lefht-rigght)>1) ans=false;

        return max(lefht,rigght)+1;

    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        f(root);
        return ans;
    }
};