class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int maxi=0;
        int prefix_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)prefix_sum++;
            else prefix_sum--;
            if(mp.find(prefix_sum)!=mp.end()){
                maxi=max(maxi,i-mp[prefix_sum]);
            }
            else mp[prefix_sum]=i;
        }
        return maxi;
             
    }                                                                           
};