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
void inorder(TreeNode* root,vector<int>&v){
 if(root==NULL)
 return ;

 inorder(root->left,v);
 v.push_back(root->val);
 inorder(root->right,v);




}



public:
    TreeNode* balanceBST(TreeNode* root) {
       
     vector<int>v;
     inorder(root,v);

    //  for(int i:v) cout<<i<<" ";
    //  cout<<endl;
     int n=v.size();
     function<TreeNode*(int,int)>f=[&](int lef, int rig)->TreeNode*{
        if(lef>rig) return NULL;
        if(lef==rig){
            return new TreeNode(v[lef]);
        }
        int mid=(lef+rig)/2;
        TreeNode* root= new TreeNode(v[mid]);
        root->left= f(lef,mid-1);
        root->right=f(mid+1,rig);
        return root;
     };
      
   return f(0,n-1);
     
    

      
    }
};