class MinStack {
public:
    stack<pair<int,int>>st;
    int mini;
    MinStack() {
        mini = pow(2, 31) - 1 ;
    }
    
    void push(int val) {
        mini = min(mini, val);
        st.push({val,mini});
    }
    
    void pop() {
       int curr_mini = st.top().second;
       st.pop();
       if(st.size() > 0)mini = st.top().second;
       else mini = pow(2, 31) - 1;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */