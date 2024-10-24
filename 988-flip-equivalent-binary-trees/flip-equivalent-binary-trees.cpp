class Solution {
private:
void f(TreeNode* root,map<int, vector<pair<int, int>>>&mp,TreeNode* par,int l){
 if(!root) return;
 mp[l].push_back({root->val,par->val});
 f(root->left,mp,root,l+1);
 f(root->right,mp,root,l+1);
 return;
 
 
}
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        TreeNode* t= new TreeNode(-1);
     map<int, vector<pair<int,int>>>mp1,mp2;
     f(root1,mp1,t,0);
     f(root2,mp2,t,0);
     for(auto &it: mp1){ 
     sort(it.second.begin(),it.second.end());
     }
      for(auto &it: mp2){ 
      sort(it.second.begin(),it.second.end());
      }
      
     
     return  mp1==mp2;
    }
};