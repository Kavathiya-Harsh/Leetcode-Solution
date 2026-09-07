// Last updated: 9/7/2026, 1:44:48 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* h) {
        if (!h) return NULL;

        for (Node* p=h; p; p=p->next->next) {
            Node* c=new Node(p->val);
            c->next=p->next; p->next=c;
        }

        for (Node* p=h; p; p=p->next->next)
            if(p->random) p->next->random=p->random->next;

        Node *ans=h->next;
        for(Node *p=h; p; p=p->next) {
            Node *c=p->next;
            p->next=c->next;
            if(c->next) c->next=c->next->next;
        }
        return ans;
    }
};