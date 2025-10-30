class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int last = 0;
        for(int i = 0; i < target.size(); i++){
            if(target[i] > last){
                ans += target[i] - last;
            }
            last = target[i];
        }
        return ans;
    }
};