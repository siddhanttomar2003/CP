class RandomizedSet {
    unordered_set<int>p;
public:
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(p.find(val)!=p.end())return 0;
        else {
          
           p.insert(val);
            return 1;
        }
    }
    
    bool remove(int val) {
        if(p.find(val)==p.end())return 0;
        else {
           
            p.erase(val);
            return 1;
        }
    }
    
    int getRandom() {
        return *next(p.begin(),rand()%p.size()); 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */