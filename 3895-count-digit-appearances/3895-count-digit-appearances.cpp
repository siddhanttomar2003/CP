class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(auto it : nums){
            int n = it;
            while(n){
                int d = n % 10;
                n /= 10;
                if(d == digit)ans++;
            }
        }
        return ans;
    }
};