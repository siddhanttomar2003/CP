class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while(true){
            vector<int>temp;
            int sum = 1e9;
            int pos = -1;
            bool check = false;
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i] + nums[i + 1] < sum){
                    sum = nums[i] + nums[i + 1];
                    pos = i;
                } 
                if(nums[i + 1] < nums[i])check = true;
            }
            if(!check)break;
            for(int i = 0; i < nums.size(); i++){
                if(i == pos){
                    temp.push_back(nums[i] + nums[i + 1]);
                    i++;
                }
                else temp.push_back(nums[i]);
            }
            nums = temp;
            count++;
        }
        return count;
    }
};