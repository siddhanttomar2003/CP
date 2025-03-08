class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
           mp[nums[i]].push_back(i);
        }
        int ans=-1;
        if(k==nums.size())return *max_element(nums.begin(),nums.end());
        for(auto it:mp){
            bool check=true;
            vector<int>pos=it.second;
            if(pos.size()>=2)check=false;
            else if(pos[0]==0)ans=max(ans,it.first);
            else if(pos[0]==n-1){
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};