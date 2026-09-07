// Last updated: 9/7/2026, 1:43:33 PM
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
    ListNode* middleNode(ListNode* head) {
         int size = 0;
    ListNode* i = head;
    while (i != NULL)
    {
        size++;
        i = i -> next;
    }

    int mid = size / 2 ;
    int count = 0;

    i = head;
    while (count < mid)
    {
     i = i -> next;
     count++;   
    }
    return i;
    }
};