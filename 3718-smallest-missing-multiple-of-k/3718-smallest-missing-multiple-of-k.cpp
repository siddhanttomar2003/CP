class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int curr = k;
        map<int, int>mp;
        int start = k;
        for(auto it : nums){
            mp[it]++;
            while(mp.find(k) != mp.end())k += start;
        }
        return k;
    }
};