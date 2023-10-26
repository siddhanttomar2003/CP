class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
  vector<int>v;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
             int more=target-a;
             if(mpp.find(more)!=mpp.end()){
            v.push_back(mpp[more]);
            v.push_back(i);
            break;
             }
             else{
                 mpp[nums[i]]=i;
             }
        }
        return v;
  
    }
};