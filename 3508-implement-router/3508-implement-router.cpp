class Router {
public:
    int limit;
    set<vector<int>>store;
    queue<vector<int>>q;
    Router(int memoryLimit) {
        limit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>temp={source,destination,timestamp};
        if(store.find(temp)!=store.end()){
            return false;
        }
        if(store.size()==limit){
            vector<int>t=q.front();
            q.pop();
            store.erase(t);
        }
        store.insert(temp);
        q.push(temp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0)return {};
        vector<int>res=q.front();
        store.erase(res);
        q.pop();
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int ans=0;
        for(auto it:store){
           if(it[1]==destination && it[2]>=startTime && it[2]<=endTime)ans++;
        }
        return ans;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */