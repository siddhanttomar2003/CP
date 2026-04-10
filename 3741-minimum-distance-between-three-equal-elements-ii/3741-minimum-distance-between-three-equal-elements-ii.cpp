class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        int mini = 1e9;
        for(auto it : mp){
            vector<int> &temp = it.second;
            int size = temp.size();
            // cout << it.first << " " << size << endl;
            for(int i = 0; i < size - 2; i++){
                mini = min(mini, (temp[i + 2] - temp[i]) * 2);
            }
        }
        return mini == 1e9 ? -1 : mini;
    }
};