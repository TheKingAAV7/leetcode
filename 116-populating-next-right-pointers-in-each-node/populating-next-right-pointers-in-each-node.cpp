/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        deque<Node*>q;
        if(!root) return NULL;
        q.push_front(root);
        while(!q.empty()){
            int n=q.size();
            stack<Node*>st;
            Node* last=q.back();
            q.pop_back();
            if(last->right) st.push(last->right);
            if(last->left) st.push(last->left);
            

            for(int i=n-2;i>=0;i--){
                Node* tmp=q.back();
                q.pop_back();
                tmp->next=last;
                last=tmp;
            if(tmp->right) st.push(tmp->right);
            if(tmp->left) st.push(tmp->left);
            }
            while(!st.empty()){
                q.push_back(st.top());
                st.pop();
            }
        }
        return root;
    }
};