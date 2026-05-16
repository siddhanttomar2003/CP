class Solution {
public:
    bool isGood(vector<int>& nums) {
        map<int, int>mp;
        int n = nums.size() - 1;
        for(auto it : nums)mp[it]++;
        int curr = 1;
        for(auto it : mp){
            if(it.first == curr){
                if(it.first == n && it.second == 2)return true;
                else if(it.second > 1)return false;
                curr++;
            }
            else return false;
        }
        return false;
    }
};