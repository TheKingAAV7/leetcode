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
        

        string s="";

        int sm=0;

        function<void(TreeNode*, string& )>f=[&](TreeNode* root,string &s)->void{
            if(root==NULL) return ;
            if(root->left==NULL and root->right==NULL){
                // this is a leaf node 
                // convert the binary string to intger 
                s.push_back(root->val+'0');
           //     cout<<s<<endl;
                int num=0;
                int n=s.length();
                for(int j=0;j<n;j++){
                    if(s[n-j-1]=='1') num+=pow(2,j);
                }
                // we have the no.
                sm+=num;
                s.pop_back();
                return;
            }

            s.push_back(root->val+'0');

            f(root->left,s);
            f(root->right,s);
            s.pop_back();
            return;
        };
        f(root,s);
        return sm;
    }
};