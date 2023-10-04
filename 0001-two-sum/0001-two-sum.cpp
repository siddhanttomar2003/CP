class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int pos1=0;
       int pos2=0;
       for(int i=0;i<nums.size()-1;i++){
         for(int j=i+1;j<nums.size();j++){
             if(nums[i]+nums[j]==target){
                 pos1=i;
                 pos2=j;

             }
         }
       }
       vector<int> v1;
       v1.push_back(pos1);
       v1.push_back(pos2);
       return v1;
        
    }
};