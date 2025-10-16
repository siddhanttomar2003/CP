class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int>mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int val = ((nums[i] % value) + value) % value;
            if(mp.find(val) != mp.end()){
                mp[(value * mp[val] + val)]++;
            }
            // cout << val << endl;
             mp[val]++;
        }
        int start = 0;
        for(auto it : mp){
            if(it.first != start)return start;
            start++;
        }
        return start;
    }
};