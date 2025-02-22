/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nuintptr), right(nuintptr) {}
 *     TreeNode(int x) : val(x), left(nuintptr), right(nuintptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    TreeNode* recoverFromPreorder(string trav) {
        vector<vector<int>>v;
        int n=trav.length();
        int i=0;
        int tmp=0;
            while(i<n and trav[i]>='0' and trav[i]<='9'){
                tmp=tmp*10+(trav[i]-'0');
                i++;
        }
        v.push_back({0,tmp});
        int pos=i;
        while(pos<n){
            int cnt=0;
            while(trav[pos]=='-'){
                cnt++;
                pos++;
            }
            tmp=0;
            while(pos<n and trav[pos]>='0' and trav[pos]<='9'){
                tmp=tmp*10+(trav[pos]-'0');
                pos++;
                }
            v.push_back({cnt,tmp});
        }
       // for(auto it:v) cout<<it[0]<<" "<<it[1]<<endl;
        stack<pair<int,TreeNode*>>st;
        TreeNode* root=new TreeNode(v[0][1]);
        TreeNode* p=root;
        st.push({0,p});
        for(int i=1;i<v.size();i++){
            int x=v[i][0]-1;
            while(!st.empty() and x!=st.top().first){
                st.pop();
            }
            
            TreeNode* tmp=st.top().second;
         //  cout<<tmp->val<<endl;
            if(tmp->left==NULL){
                tmp->left= new TreeNode(v[i][1]);
                st.push({v[i][0],tmp->left});
            }
            else{
                tmp->right= new TreeNode(v[i][1]);
                st.push({v[i][0],tmp->right});
            }
        }
        return root;;

    }
};