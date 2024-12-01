class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         int maxi=-1e9;
         map<int,int>mp;
         int n=nums.size();
         int sum=0;
         for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[nums[i]]++;
         }
         for(int i=0;i<n;i++){
            int curr=sum-nums[i];
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            if(curr%2==0 && mp.find(curr/2)!=mp.end()){
                maxi=max(maxi,nums[i]);
            }
            mp[nums[i]]++;
         }
        return maxi;
    }
};