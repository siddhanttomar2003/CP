class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
      if(q.size()>=1){
        q.push(x);
        int size=q.size();
        while(size-1){
            q.push(q.front());
            q.pop();
            size--;
        }
      }
      else q.push(x);

    }
    
    int pop() {
        int ans=q.front();
        q.pop();

        return ans;
    }
    
    int top() {
         return q.front();
    }
    
    bool empty() {
    return q.size()==0;
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