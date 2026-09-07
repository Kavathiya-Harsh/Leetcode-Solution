// Last updated: 9/7/2026, 1:44:11 PM
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *odd = head, *even = head->next, *e = even;

        while (e && e->next) {
            odd->next = e->next;
            odd = odd->next;
            e->next = odd->next;
            e = e->next;
        }

        odd->next = even;
        return head;
    }
};