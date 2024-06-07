class MyStack {
public:
    queue<int>first;
    queue<int>second;
    MyStack() {
    }
    
    void push(int x) {
        first.push(x);
        while(second.size()>0){
            first.push(second.front());
            second.pop();
        }
        swap(first,second);
 
    }
    
    int pop() {
        int ans=second.front();
        second.pop();
        return ans;
    }
    
    int top() {
        return second.front();
    }
    
    bool empty() {
        return second.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */