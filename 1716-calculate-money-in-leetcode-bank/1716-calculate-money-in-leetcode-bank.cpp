class Solution {
public:
    int totalMoney(int n) {
        int curr = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(i % 7 == 1)curr++;
            ans += (curr + (i % 7 == 0 ? 7 : i % 7) - 1);
            // cout << curr + (i % 7) - 1 << endl;
        }
        return ans;
    }
};