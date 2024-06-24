
class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
};
     Node *head=new Node(-1,-1);
     Node *tail=new Node(-1,-1);
     int cap;
     map<int,Node *>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node *newnode){
       Node *nx=head->next;
       newnode->next=nx;
       nx->prev=newnode;
       newnode->prev=head;
       head->next=newnode;   
    }
    void deletenode(Node *delnode){
        Node *nx=delnode->next;
        Node *pr=delnode->prev;
        nx->prev=pr;
        pr->next=nx;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *addr=mp[key];
            int res=addr->val;
            mp.erase(key);
            deletenode(addr);
            addnode(addr);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *ex=mp[key];
            mp.erase(key);
            deletenode(ex);
        }
        if(mp.size()==cap){
            Node *del=tail->prev;
            int res=del->key;
            mp.erase(res);
            deletenode(del);
        }
        Node *newnode=new Node(key,value);
        addnode(newnode);
        mp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */