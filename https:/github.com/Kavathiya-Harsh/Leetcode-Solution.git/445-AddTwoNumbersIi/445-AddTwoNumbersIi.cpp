// Last updated: 9/7/2026, 1:43:55 PM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;

        while(l1) a.push(l1->val), l1=l1->next;
        while(l2) b.push(l2->val), l2=l2->next;

        ListNode* ans = nullptr;
        int carry = 0;

        while(!a.empty() || !b.empty() || carry) {
            int sum = carry;

            if(!a.empty()) sum += a.top(), a.pop();
            if(!b.empty()) sum += b.top(), b.pop();

            carry = sum / 10;

            ListNode* node = new ListNode(sum % 10);
            node->next = ans;
            ans = node;
        }

        return ans;
    }
};