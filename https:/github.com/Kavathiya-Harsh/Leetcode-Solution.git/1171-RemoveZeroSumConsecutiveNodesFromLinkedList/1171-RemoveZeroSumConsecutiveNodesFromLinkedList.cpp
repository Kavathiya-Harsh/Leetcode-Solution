// Last updated: 9/7/2026, 1:43:03 PM
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> mp;
        int sum = 0;

        for (ListNode* p = &dummy; p; p = p->next) {
            sum += p->val;
            mp[sum] = p;
        }

        sum = 0;
        for (ListNode* p = &dummy; p; p = p->next) {
            sum += p->val;
            p->next = mp[sum]->next;
        }

        return dummy.next;
    }
};