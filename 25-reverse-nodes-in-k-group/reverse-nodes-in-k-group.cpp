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
    ListNode* reverse(ListNode* root) {
        ListNode* prev = nullptr;
        ListNode* curr = root;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        ListNode* rev = new ListNode(0);
        ListNode* revTemp = rev;
        int cnt = 1;

        while (head != nullptr) {
            revTemp->next = new ListNode(head->val);
            revTemp = revTemp->next;

            if (cnt % k == 0) {
                ListNode* reversed = reverse(rev->next);
                temp->next = reversed;
                while (reversed != nullptr) {
                    temp = temp->next;
                    reversed = reversed->next;
                }
                rev = new ListNode(0);
                revTemp = rev;
            }
            cnt++;
            head = head->next;
        }

        if (rev->next != nullptr) temp->next = rev->next;

        return ans->next;
    }
};