class Solution {
public:
    int cal(vector<int>&nums, int i, int curr,int tar){
        if(i==nums.size()){
            return curr==tar;
        }
        int t=cal(nums,i+1,curr|nums[i],tar);
        int nt=cal(nums,i+1,curr,tar);
        return t+nt;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi|=nums[i];
        }
    
        return cal(nums,0,0,maxi);
    }
};