class Solution {
private:
    void f(TreeNode* root, vector<int>& tmp) {
        if (!root) return;
        tmp.push_back(root->val);
        f(root->left, tmp);
        f(root->right, tmp);
    }
    
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        vector<int> tmp;
        f(root, tmp);
        
        TreeNode* curr = root; 
        for (int i = 1; i < tmp.size(); i++) {
            curr->left = nullptr;  
            curr->right = new TreeNode(tmp[i]);
            curr = curr->right;
        }
    }
};
