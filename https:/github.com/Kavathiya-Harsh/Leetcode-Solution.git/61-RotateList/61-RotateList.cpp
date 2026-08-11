// Last updated: 8/11/2026, 2:13:18 PM
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Make it circular
        temp->next = head;

        // Step 3: Optimize k
        k = k % length;
        int stepsToNewHead = length - k;

        // Step 4: Find new tail
        ListNode* newTail = temp;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        // Step 5: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};