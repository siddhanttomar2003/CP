class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        int maxi=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxi=max(maxi,mp[nums[i]]);
        }
        
        for(auto it :mp){
            if(it.second==maxi)ans+=it.second;
        }
           return ans;
    }
};