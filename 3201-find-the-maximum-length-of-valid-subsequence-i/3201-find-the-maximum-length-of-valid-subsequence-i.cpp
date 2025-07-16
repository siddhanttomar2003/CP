class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int count_o = 0;
        int n = nums.size();
        for(auto it : nums){
            if(it & 1)count_o++;
        }
        int count_e = n - count_o;
        int maxi = max(count_o, count_e);
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] & 1){
                pos = i;
                break;
            }
        }
        int start_o = 1;
        int par = 1;
        for(int i = pos + 1; i < n; i++){
            if(par == 1 && nums[i] % 2 == 0){
                start_o++;
                par ^= 1;
            }
            else if(par == 0 && (nums[i] & 1)){
                start_o++;
                par ^= 1;
            }
        }
        maxi = max(maxi, start_o);
        int start_e = 1;
        pos = -1;
         for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                pos = i;
                break;
            }
        }
        par = 0;
        for(int i = pos + 1; i < n; i++){
            if((nums[i] & 1) && par == 0){
                par ^= 1;
                start_e++;
            }
            else if((nums[i] % 2 == 0) && par == 1){
                par ^= 1;
                start_e++;
            }  
        }
        return max(maxi, start_e);
    }
};