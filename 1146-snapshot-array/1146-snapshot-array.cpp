class SnapshotArray {
public:
    map<int,int>arr;
    map<int,map<int,int>>mp;
    int snap_id;
    SnapshotArray(int length) {
        snap_id=0;
    }
    
    void set(int index, int val) {
        mp[index][snap_id]=val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
       if(mp[index].find(snap_id)!=mp[index].end())return mp[index][snap_id];
       auto it=mp[index].upper_bound(snap_id-1);
       if(it==mp[index].begin())return 0;
       auto it2=prev(it);
       return it2->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */