class Solution {
public:
    typedef long long ll;
    int findMinFibonacciNumbers(int k) {
        ll s = 0;
        ll e = 1;
        vector<ll>fib;
        fib.push_back(e);
        for(int i = 0; i < 50; i++){
            ll sum = e + s;
            if(sum > 1e9 || sum > k)break;
            s = e;
            e = sum;
            fib.push_back(e);
        }
        int count = 0;
        while(k > 0){
            int it = lower_bound(fib.begin(), fib.end(), k) - fib.begin();
            if(it < fib.size()){
                if(fib[it] == k)return count + 1;
            }
            it --;
            k -= fib[it];
            count++;
        }
        return count;
    }
};