class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];
        }
        int op=0;
        for(int i=0;i<32;i++){
         if((x&(1<<i))!=(k&(1<<i)))op++;
        }
        return op;
                                                                              
    }
};