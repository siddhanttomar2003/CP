class Dl{
    public :
    Dl *next, *prev;
    int val,key;
    Dl(int val, int key){
        this -> val = val;
        next = NULL;
        prev = NULL;
        this -> key = key;
    }
};
class LRUCache {
public:
    Dl *head, *tail;
    int cap;
    map<int,Dl *>mp;
    LRUCache(int capacity) {
        head = new Dl(-1, -1);
        tail = new Dl(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        cap = capacity;
    }
    void remove_from_Dl(Dl * node){
        Dl * last = node -> prev;
        Dl * nx = node -> next;
        last -> next = nx;
        nx -> prev = last;
    }
    void insert_in_Dl(Dl * node){
        Dl * last = tail -> prev;
        last -> next = node;
        tail -> prev = node;
        node -> next = tail;
        node -> prev = last;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        remove_from_Dl(mp[key]);
        insert_in_Dl(mp[key]);
        return mp[key] -> val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() == cap){
                mp.erase(head -> next -> key);
                remove_from_Dl(head -> next);
            }
            Dl * node = new Dl(value, key);
            insert_in_Dl(node);
            mp[key] = node;
        }
        else {
            Dl * node = mp[key];
            node -> val = value;
            node -> key = key;
            remove_from_Dl(node);
            insert_in_Dl(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */