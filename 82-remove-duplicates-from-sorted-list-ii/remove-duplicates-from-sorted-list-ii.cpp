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
    ListNode* deleteDuplicates(ListNode* head) {
        int prev=-1;
        ListNode* p= head;
        ListNode* ans=NULL;
        ListNode* lst=NULL;
        
        if(!p or p->next==NULL) return p;
        while(p!=NULL){
           int curval= p->val;

           if(p->next){
           int nxtval= p->next->val;
           //cout<<curval<<" "<<nxtval<<endl;
           if(curval==nxtval){
            while(p!=NULL and p->val==curval){
                p=p->next;
            }
          //  cout<<"YES"<<" "<<!p<<endl;
           }
           else{
            if(ans==NULL){
                ans=new ListNode(p->val);
                lst=ans;
            }
            else{
                lst->next=new ListNode(p->val);
                lst=lst->next;
            }
            p=p->next;
           }
           }


           else{
            if(ans==NULL){
                ans=new ListNode(p->val);
                lst=ans;
            }
            else{
                lst->next=new ListNode(p->val);
                lst=lst->next;
            }
            p=p->next;
           }
        }
       

        return ans;
    }
};