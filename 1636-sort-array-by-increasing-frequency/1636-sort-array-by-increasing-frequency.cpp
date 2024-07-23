class Solution {
public:
   struct Compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) {
            return p1.second < p2.second; // Sort in decreasing order of the second element
        }
        return p1.first > p2.first; // Sort in increasing order of the first element
    }
};

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
    
        vector<int>ans;
        while(pq.size()>0){
            int times=pq.top().first;
            int num=pq.top().second;
            pq.pop();
            for(int i=0;i<times;i++){
                ans.push_back(num);
            }
        }
     
        return ans;
    }
};