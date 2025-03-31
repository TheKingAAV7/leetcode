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
void dfs(TreeNode* root,int &maxi,int cur){
    if(!root) return ;
    maxi=max(maxi,cur);
    dfs(root->left,maxi,cur+1);
    dfs(root->right,maxi,cur+1);
    return;
}
void f(TreeNode* root, int &maxi,vector<TreeNode*>&mp,int cur){
    if(!root) return;
    if(cur==maxi) mp.push_back(root);
    f(root->left,maxi,mp,cur+1);
    f(root->right,maxi,mp,cur+1);
    return;
}

string lcp(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0]; 
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) { 
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

bool f1(TreeNode* root,string &tmp,TreeNode* reqnode){
if(!root) return false;
if(root==reqnode) return true;

bool c1=f1(root->left,tmp,reqnode);
bool c2=f1(root->right,tmp,reqnode);

if(c1){
    tmp.push_back('L');
    return true;
}
else if(c2){
    tmp.push_back('R');
    return true;
}
return false;

}
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxi=0;
        vector<TreeNode*>nds;
        vector<string>st;
        dfs(root,maxi,0);
        f(root,maxi,nds,0);
        for(auto it:nds){
            string tmp="";
            f1(root,tmp,it);
            
            reverse(tmp.begin(),tmp.end());
            st.push_back(tmp);
           
        }
        string ans=lcp(st);
        int pos=0;
        TreeNode* res=root;
        while(pos<ans.length()){
            if(ans[pos]=='L'){
                root=root->left;
            }
            else root=root->right;
            pos++;
        }
        return root;
    }
};