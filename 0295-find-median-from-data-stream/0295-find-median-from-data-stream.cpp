class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>min_heap;
    priority_queue<int>max_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(min_heap.size()==0 && max_heap.size()==0){
            min_heap.push(num);
        }
       else if(num>=min_heap.top()){
            min_heap.push(num);
        }
        else {
            max_heap.push(num);
        }
        while(min_heap.size()>max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        while(max_heap.size()>min_heap.size()+1){
           min_heap.push(max_heap.top());
           max_heap.pop();
        }
    }
    
    double findMedian() {
         int size=min_heap.size()+max_heap.size();
         if(size&1)return max_heap.top();
         return ((double)min_heap.top()+(double)max_heap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */