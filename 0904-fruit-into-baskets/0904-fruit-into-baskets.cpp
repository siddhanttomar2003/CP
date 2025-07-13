class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int maxi = 0;
        map<int,int>mp;
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > 2){
                if(--mp[nums[i]] == 0)mp.erase(nums[i]);
                i++; 
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};