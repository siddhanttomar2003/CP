class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0)return false;
        map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
            if(mp[it] > n / k)return false;
        }
        return true;
    }
};