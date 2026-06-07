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



    4 3 2 1
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& edges) {
        unordered_map<int,TreeNode*>mp;
        for(auto it:edges){
            int par= it[0];
            int child= it[1];
            int islef= it[2];
            TreeNode* p= NULL;
            TreeNode* c= NULL;
            if(mp.find(par)!=mp.end()){
                p=mp[par];
            }
            else p= new TreeNode(par);
            if(mp.find(child)!=mp.end()){
                c=mp[child];
            }
            else c= new TreeNode(child);
            mp[par]=p;
            mp[child]=c;

            if(islef) p->left= c;
            else p->right= c;
        }
        vector<TreeNode*>st;
        unordered_set<TreeNode*>vis;
        auto f=[&](auto &&self,TreeNode* node)->void{
            if(vis.count(node)) return;
            vis.insert(node);
            if(node->left) self(self,node->left);
            if(node->right) self(self,node->right);
            st.push_back(node);
            return;
        };
        
        for(auto it:mp){
            f(f,it.second);
        }
        return st.back();
    }
};