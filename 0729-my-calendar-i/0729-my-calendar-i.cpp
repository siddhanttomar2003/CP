class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if(!v.size()){
            v.push_back({start,end-1});
            return true;
        }
        for(int i=0;i<v.size();i++){
            if(start>=v[i].first && start<=v[i].second)return false;
            else if(end-1>=v[i].first && end-1<=v[i].second)return false;
            else if(start<=v[i].first && end-1>=v[i].second)return false;
        }
        v.push_back({start,end-1});
        sort(v.begin(),v.end());
          return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */