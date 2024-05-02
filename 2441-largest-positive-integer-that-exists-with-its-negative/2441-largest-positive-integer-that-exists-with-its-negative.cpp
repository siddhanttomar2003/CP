class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
                 mp[nums[i]]++;
        }
        int ans=INT_MIN;
        bool flag=false;
        for(auto it:mp){
            if(mp.find(-it.first)!=mp.end()){
                flag=true;
                ans=max(ans,abs(it.first));
            }
        }
        if(flag)return ans;
        return -1;
    }
};