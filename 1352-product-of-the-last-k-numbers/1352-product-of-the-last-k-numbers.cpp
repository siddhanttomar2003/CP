class ProductOfNumbers {
public:
    vector<int>pre;
    set<int>st;
    ProductOfNumbers() {
       
    }
    void add(int num) {
        int pos=pre.size();
        if(num==0)st.insert(pos);
        if(pre.size()==0){
            pre.push_back(num);
        }
        else {
            if(pre.back()==0){
                pre.push_back(num);
            }
            else 
            pre.push_back(pre.back()*num);
        }
       
    }
    
    int getProduct(int k) {
         int size=pre.size();
         int ind=size-k-1;
         auto it=st.upper_bound(ind);
         if(it!=st.end())return 0;
        
         else {
            if(k==size)return pre[size-1];
            else if(pre[size-k-1]==0)return pre[size-1];
            else return pre[size-1]/pre[size-k-1];
         }
         
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */