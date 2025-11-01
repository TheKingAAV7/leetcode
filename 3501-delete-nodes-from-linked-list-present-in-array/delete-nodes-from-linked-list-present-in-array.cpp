/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());

        ListNode* prev = NULL;
        ListNode* cur =  head;
        ListNode* root= head;
        while(cur->next!=NULL){
            int v=cur->val;
            if(st.count(v)){
                ListNode* nxt= cur->next;
                if(prev==NULL){
                    root=cur->next;
                    cur=root;
                }
                else{
                    cur->next=NULL;
                    prev->next=nxt;
                    cur=nxt;
                }
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
        //cout<<cur->val<<endl;
        if(cur!=NULL  and st.count(cur->val)){
            prev->next=NULL;
            cur=NULL;
        }
        return root;
    }
};