// Last updated: 9/7/2026, 1:41:08 PM
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        int k = 1;

        while (cur) {
            ListNode *start = cur, *end = cur;
            int cnt = 0;

            while (end && cnt < k)
                end = end->next, cnt++;

            if (cnt % 2 == 0) {
                ListNode *p = nullptr, *x = start;
                while (x != end) {
                    ListNode *n = x->next;
                    x->next = p;
                    p = x;
                    x = n;
                }

                if (prev) prev->next = p;
                else head = p;

                start->next = end;
                prev = start;
            } else {
                while (cur != end)
                    prev = cur, cur = cur->next;
            }

            cur = end;
            k++;
        }

        return head;
    }
};