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
    ListNode* mergeKLists(vector<ListNode*>& ls) {
      ListNode* head=NULL;
      ListNode* tail=NULL;
      int n=ls.size();
      priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
      for(int i=0;i<n;i++){
        if(ls[i]!=NULL){
            pq.push({ls[i]->val,ls[i]});
        }
      }
      while(!pq.empty()){
        int x=pq.top().first;
        ListNode* tmp=pq.top().second;
        pq.pop();
        if(!head){
            head= new ListNode(x);
            tail=head;
        }
        else{
            ListNode* nn= new ListNode(x);
            tail->next=nn;
            tail=nn;
        }
        tmp=tmp->next;
        if(tmp!=NULL) pq.push({tmp->val,tmp});

      }

      return head;
    }
};