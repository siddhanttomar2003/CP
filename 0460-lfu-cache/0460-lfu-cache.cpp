class LFUCache {
public:
    set<vector<int>>st;
    map<int,int>key_freq;
    map<int,int>key_val;
    map<int,int>key_last_used;
    int size;
    int last = 0;
    LFUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(key_val.find(key) == key_val.end())return -1;
        int freq = key_freq[key];
        int val = key_val[key];
        int counter = key_last_used[key];
        st.erase({freq, counter, key, val});
        key_freq[key]++;
        freq ++;
        key_last_used[key] = last;
        counter = key_last_used[key];
        last ++;
        st.insert({freq, counter, key, val});
        return val;
    }
    
    void put(int key, int value) {
        if(key_val.find(key) != key_val.end()){
            int freq = key_freq[key];
            int val = key_val[key];
            int counter = key_last_used[key];
            st.erase({freq, counter, key, val});
            key_freq[key]++;
            freq ++;
            key_val[key] = value;
            key_last_used[key] = last;
            counter = key_last_used[key];
            last ++;
            st.insert({freq, counter, key, value});
        }
        else {
            if(key_val.size() == size){
                auto it = *st.begin();
                int r_freq = it[0];
                int r_counter = it[1];
                int r_key = it[2];
                int r_val = it[3];
                key_val.erase(r_key);
                key_freq.erase(r_key);
                key_last_used.erase(r_key);
                st.erase({r_freq, r_counter, r_key, r_val});
                // cout << "key" << key << " " << "value" << value << endl;
                // cout << r_freq << " " << r_counter << " " << r_key << " " << r_val <<endl;
            }
                key_val[key] = value;
                key_freq[key]++;
                int freq = 1;
                key_last_used[key] = last;
                int counter = last;
                last ++;
                st.insert({freq, counter, key , value});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */