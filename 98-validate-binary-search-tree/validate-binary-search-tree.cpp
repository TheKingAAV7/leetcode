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
void f(TreeNode* root,vector<int>&ans){
    if(!root) return;
    f(root->left,ans);
    ans.push_back(root->val);
    f(root->right,ans);
    return;
}
public:
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        f(root,ans);
        int n=ans.size();
        for(int i=1;i<n;i++){
            if(ans[i]<=ans[i-1]) return false;
        }
        return true;
    }
};