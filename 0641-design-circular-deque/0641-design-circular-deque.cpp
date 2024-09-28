class ListNod {
    public:
  ListNod * next;
  ListNod *last;
 int val;
      ListNod (){
        next=NULL;
        last=NULL;
      }
      ListNod (int val){
        this->val=val;;
      }
};
class MyCircularDeque {
public:
     ListNod *start;
     ListNod *end;
     int c,size;
    MyCircularDeque(int k) {
        start=NULL;end=NULL;
        size=k;c=0;
    }
    bool insertFront(int value) {
        ListNod * curr=new ListNod(value);
        if(c<size){
           if(c==0){
                start=curr;
                end=curr;
           }
           else {
            curr->next=start;
            end->next=curr;
            start->last=curr;
            start=curr;
            curr->last=end;
           }
           c++;
           return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        ListNod * curr=new ListNod(value);
        if(c<size){
           if(c==0){
                start=curr;
                end=curr;
           }
           else {
             end->next=curr;
             curr->last=end;
             curr->next=start;
             end=curr;
             start->last=end;
           }
           c++;
           return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(c!=0){
            if(c==1){
                start=nullptr;end=nullptr;
            }
            else {
                start=start->next;
                end->next=start;
                start->last=end;
            }
            c--;
           return true;
        }
        else  return false;
    }
    
    bool deleteLast() {
        if(c!=0){
          if(c==1){
            start=NULL;
            end=NULL;
          }
          else {
            end=end->last;
            end->next=start;
            start->last=end;
          }
          c--;
          return true;
        }
        return false;
    }
    
    int getFront() {
        if(c>0)return start->val;
        return -1;
    }
    
    int getRear() {
        if(c>0)return end->val;
        return -1;
    }
    
    bool isEmpty() {
        return c==0;
    }
    
    bool isFull() {
        return c==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */