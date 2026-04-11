class Solution {
public:
    vector<bool>primes;
    void build_primes(int n){
        primes.resize(n + 1, true);
        primes[0] = primes[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(primes[i]){
                for(int j = i * i; j <= n; j += i){
                    primes[j] = false;
                }
            }
        }
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        build_primes(2e5);
        vector<int>num;
        for(int i = 0; i <= 2e5; i++){
            if(primes[i])num.push_back(i);
        }
        int op = 0;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            if(i % 2 == 0){
                auto it = lower_bound(num.begin(), num.end(), curr) - num.begin();
                cout << num[it] << " " <<  i << endl;
                op += num[it] - curr;
            }
            else {
                auto it = lower_bound(num.begin(), num.end(), curr) - num.begin();
                    if(num[it] != curr)op += 0;
                    else if(curr == 2)op += 2;
                    else op += 1;
                
            }
        }
        return op;
    }
};