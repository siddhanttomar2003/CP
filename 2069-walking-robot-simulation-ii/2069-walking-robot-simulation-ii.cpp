class Robot {
public:
    vector<vector<int>>curr;
    int size;
    int idx;
    bool is_first;
    Robot(int width, int height) {
        for(int i = 0; i < width; i++)curr.push_back({i, 0, 1});
        for(int i = 1; i < height; i++)curr.push_back({width - 1, i, 2});
        for(int i = width - 2; i >= 0; i--)curr.push_back({i, height - 1, 3});
        for(int i = height - 2; i > 0; i--)curr.push_back({0, i, 4});
        size = curr.size();
        idx = 0;
        is_first = true;
        // for(int i = 0; i < size; i++)cout << curr[i][0] << " " << curr[i][1] << " " << curr[i][2] << endl;
    }
    
    void step(int num) {
        idx = (idx + num) % size;
        is_first = false;
    }
    
    vector<int> getPos() {
        return {curr[idx][0], curr[idx][1]};
    }
    
    string getDir() {
        int pos = curr[idx][2];
        if(curr[idx][0] == 0 && curr[idx][1] == 0){
            if(!is_first)return "South";
        }
        if(pos == 1)return "East";
        if(pos == 2)return "North";
        if(pos == 3)return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */