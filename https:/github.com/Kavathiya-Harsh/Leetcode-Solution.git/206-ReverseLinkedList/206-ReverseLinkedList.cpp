// Last updated: 8/11/2026, 2:12:41 PM
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next; // step 1
            curr->next = prev;           // step 2 (reverse)
            prev = curr;                 // step 3
            curr = next;                 // move ahead
        }

        return prev; // new head
    }
};