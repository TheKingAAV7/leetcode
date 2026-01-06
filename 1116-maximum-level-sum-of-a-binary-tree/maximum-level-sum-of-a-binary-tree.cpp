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
    void dfs(int levl, TreeNode* root, map<int,int>&mp){
        if(!root) return;
        mp[levl]+=root->val;
        dfs(levl+1,root->left,mp);
        dfs(levl+1,root->right,mp);
        return;
        
    }
    int maxLevelSum(TreeNode* root) {
        


        map<int,int>mp;
        dfs(1,root,mp);
        int level=-1;
        int maxi=INT_MIN;
        for(auto it:mp){
          //  cout<<it.first<<" "<<it.second<<endl;
            if(it.second>maxi){
                maxi=it.second;
                level=it.first;
            }
        }

        return level;
    }
};