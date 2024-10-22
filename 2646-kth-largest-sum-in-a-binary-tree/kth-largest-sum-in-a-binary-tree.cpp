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
        long long sm=0;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* tmp;
        int n;
        while(!q.empty()){
            sm=0;
            n=q.size();
            for(int i=0;i<n;i++){
                
                tmp=q.front();
                 q.pop();
                sm+=tmp->val;
               
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            ans.push_back(sm);
        } 
        

        sort(ans.begin(),ans.end(),greater<long long>());
        return (k-1)>=ans.size()?-1:ans[k-1];
         
       
        
    }
};