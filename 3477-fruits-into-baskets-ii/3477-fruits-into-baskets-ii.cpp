class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int m = b.size();
        vector<int>vis(m, 0);
        for(auto it : f){
            for(int i = 0; i < m; i++){
                if(b[i] >= it && !vis[i]){
                    vis[i] = 1;
                    break;
                }
            }
        }
        int count = 0;
        for(auto it : vis)if(!it)count++;
        return count;
    }
};