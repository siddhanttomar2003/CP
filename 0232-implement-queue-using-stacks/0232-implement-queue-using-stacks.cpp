class MyQueue {
public:
   stack<int>s;
   stack<int>v;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!s.empty()){
            while(!s.empty()){
                v.push(s.top());
                s.pop();
            }
            s.push(x);
            while(!v.empty()){
                s.push(v.top());
                v.pop();
            }
        }
        else s.push(x);
    }
   
    
    
    int pop() {
        int a=s.top();
        s.pop();
        return a;
    }
    
    int peek() {
       
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
   
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */