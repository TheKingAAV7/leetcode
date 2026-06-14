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
    int pairSum(ListNode* head) {
        int MX=1e5;
        vector<int>mp(MX,0);
        int pos=0;

        ListNode* prev= NULL;
        while(head){
            mp[pos++]+=head->val;
            ListNode* nxt= head->next;
            head->next= prev;
            prev=head;
            head= nxt;
        }
        int n=pos;
        cout<<n<<endl;
        int ans=0;
        int npos=n-1;
        while(prev){
           ans=max(ans,prev->val+mp[n-npos-1]);
           npos--;
           prev=prev->next;
        }
        return ans;
    }
};