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
vector<int> f(TreeNode* &root, int limit, int sm){
    if(!root) return {};
    if(root->left==NULL and root->right==NULL){
        
        sm+=root->val;
        if(sm<limit) root=NULL;
        return {sm};
    }
    vector<int> lef=f(root->left,limit,sm+root->val);
    vector<int> rig=f(root->right,limit,sm+root->val);
    bool m1=true,m2=true;
    // cout<<root->val<<endl;
    // for(int i:lef) cout<<i<<" ";
    // for(int i:rig) cout<<i<<" ";
    // cout<<endl;
    for(int i:lef){
        if(i>=limit){
            m1=false;
            break;
        }
    }
    for(int i:rig){
        if(i>=limit){
            m2=false;
         
        }
        lef.push_back(i);
    }
     
   
    if(m1 and m2) {
    root=NULL;
    }
    return lef;
    
}
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
         f(root,limit,0);
         return root;
    }
};