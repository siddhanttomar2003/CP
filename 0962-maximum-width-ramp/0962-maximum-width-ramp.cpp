class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans=0;
        vector<pair<int,int>>v;
        int index;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.rbegin(),v.rend());
        index=v[0].second;
        for(int i=1;i<nums.size();i++){
            ans=max(ans,index-v[i].second);
          index=max(index,v[i].second);
        }
        return ans;
    }
};