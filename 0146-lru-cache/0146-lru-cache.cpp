class Node {
    public:
    int val,key;
    Node *prev,*next;
    Node(int key,int val){
        this->val=val;
        this->key=key;
        prev=next=NULL;
    }
};
class LRUCache {
public:
    map<int,Node*>mp;
    Node *head,*tail;
    int max_size;
    LRUCache(int capacity) {
        max_size=capacity;
        head=tail=NULL;
    }
    void remove(int key){
        Node *curr=mp[key];
        if(curr->prev!=NULL){
            curr->prev->next=curr->next;
        }
        else {
            head=head->next;
            if(head!=NULL)
            head->prev=NULL;
        }
        if(curr->next!=NULL){
               curr->next->prev=curr->prev;
        }
        else {
            tail=curr->prev;
            if(tail!=NULL)
            tail->next=NULL;
        }
        mp.erase(key);
    }
    void add(int key, int value){
        Node * newnode= new Node(key,value);
        mp[key]=newnode;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
             int val=mp[key]->val;
             remove(key);
             add(key,val);
             return val;
        }
         return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            remove(key);
            add(key,value);
        }
        else {
            if(mp.size()==max_size){
                int k=head->key;
                remove(k);
            }
            add(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */