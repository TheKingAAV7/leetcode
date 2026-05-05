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
    ListNode* rotateRight(ListNode* head, long long k) {
        if(head==NULL)
        return NULL;
        if(head->next==NULL){
            return head;
        }
        long long cnt=0;
        ListNode* ans=head;
        ListNode* temp=head;
        while(temp->next->next!=NULL){
       temp=temp->next;
       cnt++;

        }
        cnt+=2;
        ListNode* prev= temp;
        ListNode* tail=temp->next;
         k=k%cnt;        
      //  cout<<prev->val<<" "<<tail->val<<endl;
        for(long long i=0;i<k;i++){
         tail->next=head;
         
         prev->next=NULL;
         
         head=tail;

         
         tail=prev;
           ListNode* ssb=head;
         while(ssb->next->next!=NULL){
       ssb=ssb->next;

        }

        prev=ssb;
        
        
       
        




        }

        
        return head;

        
    }
};