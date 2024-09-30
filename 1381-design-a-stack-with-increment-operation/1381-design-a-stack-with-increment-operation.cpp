class CustomStack {
public:
    vector<int>st;
    int c;
    int size;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        c= -1;
        size=maxSize;
    }
    
    void push(int x) {
        if(c==size-1)return;
        st[++c]=x;
    }
    
    int pop() {
        if(c==-1)return -1;
        return st[c--];
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,c+1);i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */