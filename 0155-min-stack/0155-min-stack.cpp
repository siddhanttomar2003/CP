typedef long long ll;
class MinStack {
public:
    stack<pair<ll,ll>>st;
    ll mini=1e10;
    MinStack() {
        
    }
    
    void push(int val) {
        mini=min(mini,(ll)val);
        st.push({val,mini});
    }
    
    void pop() {
        st.pop();
        if(!st.empty())mini=st.top().second;
        else mini=1e10;
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