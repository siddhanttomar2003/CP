class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int times = 0;
        for(int i = 0; i < nums.size(); i++){
            if(times == 0){
                ele = nums[i];
                times = 1;
            }
            else if(nums[i] == ele) times++;
            else times --;
        }
        return ele;
    }
};