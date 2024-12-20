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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        stack<int>st;
        q.push(root);
        st.push(root->val);
        int cnt=0;
    
     
        while(!q.empty()){
           int n=q.size();
      
           if(cnt%2==0){
            for(int i=0;i<n;i++){
              TreeNode* tmp=  q.front();
              q.pop();
              if(tmp->left){
              q.push(tmp->left);
               st.push(tmp->left->val);
              }

              if(tmp->right){
                q.push(tmp->right);
                st.push(tmp->right->val);
              }
             
             
              
            }
           }
           else{
            // 11 13 7
            
            for(int i=0;i<n;i++){
            
            TreeNode *tmp=q.front();
            int stmp=st.top();
           st.pop();
            q.pop();
            tmp->val=stmp;
          //  cout<<tmp->val<<"->"<<stmp->val<<endl;
           
            
            if(tmp->left){
            q.push(tmp->left);
            }

            if(tmp->right){
            q.push(tmp->right);
            }
             
           
            }

           }
           cnt++;
        }

           return root;
           
    }
};