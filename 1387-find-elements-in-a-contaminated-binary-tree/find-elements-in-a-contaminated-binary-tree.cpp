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
class FindElements {
private:
 map<int,int>mp;
void f(TreeNode* root){
    if(!root) return;
    
    if(root->left!=NULL){
      //  cout<<"EYS"<<endl;
        root->left->val=2*root->val+1;
        //cout<<root->left->val;
        mp[root->left->val]++;
        f(root->left);
    }
    if(root->right!=NULL){
        root->right->val=2*root->val+2;
         mp[root->right->val]++;
         f(root->right);
    }
    return;
}
public:
   
    FindElements(TreeNode* root) {
        root->val=0;
        mp[0]++;
        f(root);
    }
    
    bool find(int target) {
        return mp.find(target)!=mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */