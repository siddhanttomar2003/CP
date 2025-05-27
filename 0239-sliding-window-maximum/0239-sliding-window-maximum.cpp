class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        ans.push_back(mp.rbegin()->first);
        int j=k,i=0;
        while(j<n){
            mp[nums[j]]++;
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;j++;
            ans.push_back(mp.rbegin()->first);
        }
        return ans;
    }
};
