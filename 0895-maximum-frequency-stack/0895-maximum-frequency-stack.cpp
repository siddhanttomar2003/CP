class FreqStack {
public:
    map<int,int>val_freq;
    map<int,vector<int>>val_pos;
    set<vector<int>>st;
    int pos;
    FreqStack() {
        pos = 0;
    }
    
    void push(int val) {
        if(val_freq.find(val) == val_freq.end()){
            val_freq[val] = 1;
            val_pos[val].push_back(++pos);
            st.insert({1, pos, val});
        }
        else {
            int freq = val_freq[val];
            int posi = val_pos[val].back();
            st.erase({freq, posi, val});
            val_freq[val]++;
            val_pos[val].push_back(++pos);
            st.insert({freq + 1, pos, val});
        }
    }
    
    int pop() {
        auto it = *st.rbegin();
        int freq = it[0];
        int pos = it[1];
        int val = it[2];
        if(freq == 1){
            val_freq.erase(val);
            val_pos.erase(val);
            st.erase({freq, pos, val});
        }
        else {
            st.erase({freq, pos, val});
            val_freq[val]--;
            val_pos[val].pop_back();
            st.insert({freq - 1, val_pos[val].back(), val});
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */