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


 first capture all the deepest leaves
 for each node see, if it contains all those deepest leaves, if yest , it is the answer
 if there are mulitple such nodes, pick the one which has largest depth..
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        map<int,vector<TreeNode*>>mp;
        map<TreeNode*, int>dep;
        
        function<void(TreeNode* ,int )>capturedeep=[&](TreeNode* cur, int depth){
            if(!cur) return;
            mp[depth].push_back(cur);
            dep[cur]=depth;
            if(cur->left) capturedeep(cur->left, depth+1);
            if(cur->right) capturedeep(cur->right,depth+1);

            return;
        };
        capturedeep(root,0);
        int lst= mp.rbegin()->first;
        vector<TreeNode*>leaves= mp.rbegin()->second;
        sort(leaves.begin(),leaves.end());
       
        TreeNode* ans= NULL;

        function<void(TreeNode* , vector<TreeNode*>&)>check=[&](TreeNode* cur, vector<TreeNode*>&tmp){
            if(dep[cur]==lst) tmp.push_back(cur);
            if(cur->left) 
            check(cur->left,tmp);
            if(cur->right)
             check(cur->right,tmp);
            return; 
         };
        function<void(TreeNode*)>dfs=[&](TreeNode* cur)->void{
            if(ans!=NULL) return;
            if(cur->left)
            dfs(cur->left);
            if(cur->right) dfs(cur->right);
            vector<TreeNode*>tmp;
            check(cur,tmp);
            if(ans==NULL and tmp.size()== leaves.size()){
                ans= cur;
                return;
            }
        };

        dfs(root);
        return ans;
        
    }
};