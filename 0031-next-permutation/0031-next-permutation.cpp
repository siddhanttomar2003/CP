class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int last_pos = -1;
        int i = n - 1;
        while(i - 1 >= 0 && nums[i - 1] >= nums[i])i--;
        last_pos = i - 1;
        cout<<last_pos<<endl;
        if(last_pos == -1)reverse(nums.begin(),nums.end());
        else {
            int j = n - 1;
            while(nums[j] <= nums[last_pos]){
                j--;
            }
            swap(nums[last_pos], nums[j]);
            reverse(nums.begin()+last_pos+1,nums.end());
        }
        return;
    }
};