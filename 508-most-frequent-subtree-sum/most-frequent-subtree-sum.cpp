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
int f(TreeNode* root, int sm,unordered_map<int,int>&mp){
    if(!root) return 0;
    if(root->left==NULL and root->right==NULL){
        mp[root->val]++;
        return root->val;
    }
    int lef=f(root->left,sm,mp);
    int rig=f(root->right,sm,mp);
    
    mp[rig+lef+root->val]++;
    return rig+lef+root->val;
}
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        f(root,0,mp);
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[&](pair<int,int>a, pair<int,int>b){
            if(a.second==b.second){
                return b.first>a.first;
            }
            return a.second>b.second;
        });
        vector<int>ans;
        for(auto it:v){
            // cout<<it.first<<"->"<<it.second<<endl;
           if(it.second==v[0].second) ans.push_back(it.first);
        }
        return ans;
    }
};