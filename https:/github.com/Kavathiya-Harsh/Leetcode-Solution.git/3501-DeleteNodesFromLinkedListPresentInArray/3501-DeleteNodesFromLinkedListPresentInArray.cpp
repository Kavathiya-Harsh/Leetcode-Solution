// Last updated: 8/11/2026, 2:10:54 PM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        while (head && s.count(head->val))
            head = head->next;

        for (ListNode* p = head; p && p->next; ) {
            if (s.count(p->next->val))
                p->next = p->next->next;
            else
                p = p->next;
        }

        return head;
    }
};