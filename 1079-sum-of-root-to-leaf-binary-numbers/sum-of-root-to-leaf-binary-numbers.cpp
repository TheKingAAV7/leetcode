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
    int sumRootToLeaf(TreeNode* root) {
        int sm=0;

        function<void(TreeNode* , string& )>f=[&](TreeNode* root,string &s)->void{
            if(!root) return ;
            if(!root->left and !root->right){
                s.push_back(root->val+'0');
                int tmp=0;
                for(int j=0;j<s.length();j++){
                    if(s[s.length()-j-1]=='1'){
                        tmp+=(1<<j);
                    }
                }
                sm+=tmp;
                s.pop_back();
                return;
            }
            s.push_back(root->val+'0');
            f(root->left,s);
            f(root->right,s);
            s.pop_back();
            return;
        };
        string cur;
        f(root,cur);
        return sm;
    }
};