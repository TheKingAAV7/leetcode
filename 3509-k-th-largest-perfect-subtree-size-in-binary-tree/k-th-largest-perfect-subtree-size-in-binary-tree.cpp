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

int f(TreeNode* root, vector<int>&ans){
    if(!root) return -1;
    if(!root->right and !root->left){
        ans.push_back(1);
     return 1;
    }
    int r=-1,l=-1;
    if(root->left)
    l=f(root->left,ans);
    if(root->right)
    r=f(root->right,ans);
    if(r==-1 || l==-1 || r!=l) return -1;
    //  cout<<root->val<<endl;
    //  cout<<r<<" "<<l<<endl;
    ans.push_back(r+1+l);
    
    return r+1+l;
}
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int>ans;
        f(root,ans);
        sort(ans.begin(),ans.end(),greater<int>());
        for(int i: ans) cout<<i<<" ";
        cout<<endl;
        if((k-1)>=ans.size()) return -1;
        return ans[k-1];
    }
};