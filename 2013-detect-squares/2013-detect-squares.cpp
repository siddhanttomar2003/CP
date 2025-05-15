class DetectSquares {
public:
    map<pair<int, int>, int> mp;
    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        mp[{x, y}]++;
    }

    int count(vector<int> point) {
        int cx = point[0];
        int cy = point[1];
        int ans = 0;
        for (auto it : mp) {
            int x = it.first.first;
            int y = it.first.second;
            int len;
            if (x == cx && y!=cy) {
                len = abs(cy - y);
                if (mp.find({x - len, y}) != mp.end() &&
                    mp.find({x - len, cy}) != mp.end()) {
                        ans+=(it.second*(mp[{x-len,y}])*mp[{x-len,cy}]);
                }
                  if (mp.find({x + len, y}) != mp.end() &&
                    mp.find({x + len, cy}) != mp.end()) {
                        ans+=(it.second*(mp[{x+len,y}])*mp[{x+len,cy}]);
                }
            }
      
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */