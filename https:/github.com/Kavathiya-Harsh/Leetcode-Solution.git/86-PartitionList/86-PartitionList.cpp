// Last updated: 8/11/2026, 2:13:07 PM
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
    ListNode* partition(ListNode* head, int x) {
        ListNode before(0), after(0);
        ListNode *b = &before, *a = &after;
        
        while (head) {
            (head->val < x ? b : a)->next = head;
            (head->val < x ? b : a) = (head->val < x ? b : a)->next;
            head = head->next;
        }
        
        a->next = NULL;
        b->next = after.next;
        
        return before.next;
    }
};