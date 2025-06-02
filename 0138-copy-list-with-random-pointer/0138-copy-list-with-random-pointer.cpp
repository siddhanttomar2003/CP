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
    Node* copyRandomList(Node* head) {
        Node* new_head = NULL;
        Node* tail = NULL;
        Node* curr = head;
        map<Node *,Node *>address;
        int c=0;
        while (curr != NULL) {
            Node* newnode = new Node(curr->val);
            newnode->random = curr->random;
            if (new_head == NULL) {
                new_head = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
            address[curr]=newnode;
            curr = curr->next;
        }
        Node *temp1=new_head;
        Node *temp2=head;
        while(temp1!=NULL){
            temp1->random=address[temp2->random];
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return new_head;
    }
};