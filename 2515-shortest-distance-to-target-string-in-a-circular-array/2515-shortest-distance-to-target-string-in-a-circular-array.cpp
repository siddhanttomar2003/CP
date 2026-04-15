class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int>pos;
        int n = words.size();
        for(int i = 0; i < n; i++){
            if(words[i] == target)pos.push_back(i);
        }
        int idx = lower_bound(pos.begin(), pos.end(), startIndex) - pos.begin();
        int mini = 1e9;
        if(idx < pos.size()){
            mini = min(mini, pos[idx] - startIndex);
        }
        if(idx - 1 >= 0){
            mini = min(mini, startIndex - pos[idx - 1]);
        }
        int size = pos.size();
        if(size > 0  && pos[0] < startIndex){
            mini = min(mini, n - startIndex + pos[0]); 
        }
        if(size > 0 && pos[size - 1] > startIndex){
            mini = min(mini, n - pos[size - 1] + startIndex);
        }
        return mini == 1e9 ? -1 : mini;
    }
};