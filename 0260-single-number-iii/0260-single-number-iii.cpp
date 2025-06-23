typedef long long ll;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<ll>ans;
        ll xori = 0;
        ll n = nums.size();
        for(ll i = 0; i < n; i++){
            xori ^= nums[i];
        }
        // last set bit 
        
        ll num =  (xori & (xori - 1)) ^ xori;
        ll pos = log2(num);
        
        ll buck1 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] & (1 << pos))buck1 ^= nums[i];
        }
        return {(int)buck1 ,(int)( xori ^ buck1 )};
    }
};