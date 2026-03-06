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
9 1 4 5 
 */

class Solution {
public:
    int rob(TreeNode* root) {
        map<TreeNode*,int>dp;
        function<int(TreeNode* )>f=[&](TreeNode* root)->int{
            if(!root) return 0;
            if(dp.find(root)!=dp.end()) return dp[root];
            int ans=0;
            

            int ntake= f(root->left) + f(root->right);
            int take=root->val;
         
            int ll,lr,rl,rr;
            ll=lr=rl=rr=0;
            if(root->left){
            ll= f(root->left->left);
            lr= f(root->left->right);
            }
            if(root->right){
                rl=f(root->right->left);
                rr=f(root->right->right);
            }
            take=  root->val + ll+lr+rl+rr;
            
            return dp[root]=max(take,ntake);
        };
        return f(root);
    }
};