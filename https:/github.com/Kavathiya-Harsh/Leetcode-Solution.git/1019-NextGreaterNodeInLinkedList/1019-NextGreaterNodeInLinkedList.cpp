// Last updated: 9/7/2026, 1:43:16 PM
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> a, ans;
        stack<int> st;

        while (head) {
            a.push_back(head->val);
            head = head->next;
        }

        ans.resize(a.size(), 0);

        for (int i = 0; i < a.size(); i++) {
            while (!st.empty() && a[st.top()] < a[i]) {
                ans[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};