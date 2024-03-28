class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        int len=0;
        while(j<nums.size()){
            if(mp[nums[j]]<k){
                mp[nums[j]]++;
                j++;
            }
            else{             
                len=max(len,j-i);
                mp[nums[i]]--;
                i++;
            }
        }
        len=max(len,j-i);
        return len;
    }
};