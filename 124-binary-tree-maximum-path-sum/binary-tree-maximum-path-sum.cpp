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
 we want to find the maximum sm
 the structure is  that
 the path sm will either start from a node end on left or right or on both sides
 dp[i] -> represents maximum sm ending either on right or left
 dp[i]= max(dp[lef],dp[rig])
 ans=max(ans,dp[lef]+val+dp[rig],dp[lef]+val)
 */
class Solution {
public:
    map<TreeNode*,int>dp;
    int ans=0;
    int mx=INT_MIN;
    void f(TreeNode* root){
        if(!root) return;
        if(!root->left and !root->right) {
        dp[root]= max(0,root->val);
        ans=max(ans,root->val);
        mx=max(mx,root->val);
        return;
        }
        f(root->left);
        f(root->right);
        int value= root->val;
        mx=max(mx,value);
        ans=max(ans,value);
        int lefsm=0;
        int rigsm=0;
        if(root->left) lefsm= dp[root->left];
        if(root->right) rigsm= dp[root->right];
        ans=max({ans,lefsm+value+rigsm,lefsm+value,rigsm+value});
        dp[root]=max({lefsm+value,rigsm+value});
        return;
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans==0?mx:ans;
    }
};