// Last updated: 9/7/2026, 1:43:39 PM
class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* cur = head; cur; cur = cur->next) {
            if (!cur->child) continue;

            Node *c = cur->child, *n = cur->next;
            cur->next = c;
            c->prev = cur;
            cur->child = nullptr;

            while (c->next) c = c->next;
            c->next = n;
            if (n) n->prev = c;
        }
        return head;
    }
};