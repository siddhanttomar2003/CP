/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void make_list(Node * &newhead, Node * &tail, Node * head){
        if(head == NULL)return;
        Node * newnode = new Node(head -> val);
        if(newhead == NULL){
            newhead = newnode;
            tail = newnode;
        }
        else {
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
        }
        if(head -> child != NULL){
            make_list(newhead, tail , head -> child);
        }
        
            make_list(newhead, tail , head -> next);
        
    }
    Node* flatten(Node* head) {
        Node * newhead = NULL;
        Node * tail = NULL;
        make_list(newhead, tail, head);
        return newhead;
    }
};