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
    int cnt=0;
    int f(TreeNode* root){
        if(!root) return 0;
      
        int lef= f(root->left);
        int rig= f(root->right);
        int mx= max(lef,rig);
        mx=max(mx,root->val);
        // cout<<root->val<<" -> "<<mx<<endl;
        if( (root->val)==mx) cnt++;
        return mx;
    }

    int countDominantNodes(TreeNode* root) {
        f(root);
        return cnt;
    }
};