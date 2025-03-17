class Solution {
public:
     vector<int>f;
     bool divideArray(vector<int>& nums) {
     int n=nums.size();
     int maxi=*max_element(nums.begin(),nums.end());
     f.resize(maxi+1,0);
     for(int i=0;i<n;i++)f[nums[i]]++;
     for(int i=1;i<=maxi;i++)if(f[i]&1)return false;
     return true;
    }
};