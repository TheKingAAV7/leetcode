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

 #define ll long long
class Solution {
public:
    int MOD=1e9+7;
    int maxProduct(TreeNode* root) {
        ll mx = LLONG_MIN;
        ll sm=0;
        
        function<void(TreeNode*)>dfs=[&](TreeNode* root)->void{
            if(!root) return ;
            sm+=root->val;
            dfs(root->left);
            dfs(root->right);
            return;
        };
        function<int(TreeNode*)>dfs1=[&](TreeNode* root)->int{
            if(!root) return 0;
            int cursm=root->val;
            int lefsm= dfs1(root->left);
            int rigsm= dfs1(root->right);
            int rem1= sm-lefsm;
            int rem2= sm-rigsm;
            ll one= 1ll*rem1*lefsm;
            ll two= 1ll*rem2*rigsm;
            mx= max({one,two,mx});
            return cursm+lefsm+rigsm;
            
        };
        dfs(root);
        dfs1(root);
        return mx%MOD;
        
    }
};