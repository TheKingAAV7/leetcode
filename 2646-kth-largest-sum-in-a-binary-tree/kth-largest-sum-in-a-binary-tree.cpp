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
void f(TreeNode* root, unordered_map<int,long long>&mp,int l){
    if(!root) return ;
    mp[l]+=(root->val);
    f(root->left,mp,l+1);
    f(root->right,mp,l+1);
    return;

}
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long >ans;
        unordered_map<int, long long>mp;
        long long sm=0;
        int l=0;
        f(root,mp,l);    
        for(auto it: mp) ans.push_back(it.second);
        sort(ans.begin(),ans.end(),greater<long long>());
        
        return  (k-1)>=ans.size()?-1:ans[k-1];
        
    }
};