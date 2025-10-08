class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int>bits(32, 0);
        int xori = 0;
        for(auto it : nums){
            for(int i = 0; i < 32; i++){
                if(it & (1 << i))bits[i]++;
            }
            xori ^= it;
        }
        for(int i = 0; i < 32; i++){
            if(bits[i] != 0){
                if(bits[i] & 1){
                    return n;
                }
                else {
                    if(xori != 0)return n;
                    return n - 1;
                }
            }
        }
        return 0;
    }
};