// Last updated: 9/7/2026, 1:40:27 PM
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
    ListNode* removeNodes(ListNode* head) {
        // Reverse
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;

        // Remove smaller nodes
        int mx = 0;
        ListNode *p = nullptr;
        cur = head;

        while (cur) {
            if (cur->val >= mx) {
                mx = cur->val;
                p = cur;
            } else {
                p->next = cur->next;
            }
            cur = cur->next;
        }

        // Reverse again
        prev = nullptr;
        cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};