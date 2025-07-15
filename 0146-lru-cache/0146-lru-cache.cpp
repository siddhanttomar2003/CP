class Node{
   public : 
   Node * prev;
   Node * next;
   int val , key;
   Node(){
     next = NULL;
     prev = NULL;
   }
   Node(int val){
     this -> val = val;
     next = NULL;
     prev = NULL;
   }
};
class LRUCache {
public:
    // will need a key to node mapping 
    map<int,Node *>mp;
    Node * head;
    Node * tail;
    int size;

    LRUCache(int capacity) {
        size = capacity;
        head = new Node();
        tail = new Node();
        head =  NULL;
        tail = NULL;
    }
    void remove(Node * curr){
        Node * p = curr -> prev;
        Node * n = curr -> next;
        if(n != NULL){
            n -> prev = p;
        }
        else tail = p;
        if(p != NULL){
            p -> next = n;
        }
        else head = n;
    }
    void add_last(Node * curr){
        if(head == NULL){
            head = curr;
            tail = curr;
        }
        else {
            tail -> next = curr;
            curr -> prev = tail;
            tail = curr;
        }
    }
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        Node * curr = mp[key];
        remove(curr);
        add_last(curr);
        return curr -> val;
    }
    
    void put(int key, int value) {
        if(size == mp.size() && mp.find(key) == mp.end()){
            int k = head -> key;
            remove(head);
            mp.erase(k);
        }
        if(mp.find(key) != mp.end()){
            Node * curr = mp[key];
            remove(curr);
            add_last(curr);
            curr -> val = value;
        }
        else {
            Node * newnode = new Node(value);
            newnode -> key = key;
            mp[key] = newnode;
            add_last(newnode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */