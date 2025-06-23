class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int f_pos = 0;
        while( f_pos < n && nums[f_pos] != 0){
            f_pos ++;
        }
        if(f_pos == n)return ;
        int s = f_pos;
        for(int j = f_pos + 1; j < n; j++){
            if(nums[j] != 0){
                swap(nums[j],nums[s]);
                s++;
            }
        }


    }
};