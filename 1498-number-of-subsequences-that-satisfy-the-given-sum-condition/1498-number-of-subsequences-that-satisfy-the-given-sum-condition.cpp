typedef long long ll;
class Solution {
public:
    const int m = 1e9 + 7;
    ll bin_expo(ll a, ll b){
        ll res = 1;
        while(b > 0){
            if(b & 1){
            res = (a * res) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        ll tot = bin_expo((ll)2, (ll)n) - 1;
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; i--){
            int a = nums[i];
            int ind = i;
            if(target <= a){
               tot = (tot - bin_expo((ll)2, (ll)ind) + m) % m;
            }
            else if(target - a >= a)break;
            else {
                ind = upper_bound(nums.begin(), nums.end(), target - a) - nums.begin();
                if(ind == n)continue;
                else {
                    int times = i - ind;
                    int diff = bin_expo((ll)2, (ll)times);
                    // cout << i << " " << diff << endl;
                    tot = (tot - diff + m) % m;
                }
            }

        }
        return tot ;
    }
};