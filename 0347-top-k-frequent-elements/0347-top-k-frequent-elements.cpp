class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            pair<int,int>p;
            p.first=it.second;
            p.second=it.first;
            v.push_back(p);
        }
        sort(v.rbegin(),v.rend());
        int i=0;
        while(k--){
            ans.push_back(v[i].second);
            i++;
        }
        return ans;

    }
};