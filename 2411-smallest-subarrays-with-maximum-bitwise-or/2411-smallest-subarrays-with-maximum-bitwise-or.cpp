class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
       vector<int>bits(32, 0);
       int n = nums.size();
       vector<int>ans;
       for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 32; j++){
                if(nums[i] & (1 << j)){
                    bits[j] = i;
                }
            }
            int maxi = *max_element(bits.begin(), bits.end());
            // cout << maxi << endl;
            ans.push_back(max(1, maxi - i + 1));
       }
       reverse(ans.begin(), ans.end());
       for(int i = 0; i < ans.size(); i++){

       }
       return ans;
    }
};