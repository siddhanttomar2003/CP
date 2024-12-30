class Solution {
public:
    int dp[100001];
    const int m = 1e9 + 7;
    int cal(int i, int l, int h, int zero, int one) {
        if (i + 1 > h)
            return 0;
            if(dp[i]!=-1)return dp[i];
        int ways1 = 0, ways2 = 0;
        int newlen1 = i + zero;
        if (newlen1 <= h && newlen1 >= l)
            ways1 = 1 + cal(i + zero, l, h, zero, one);
        else
            ways1 = cal(i + zero, l, h, zero, one);
        int newlen2 = i + one;
        if (newlen2 <= h && newlen2 >= l)
            ways2 = 1 + cal(i + one, l, h, zero, one);
        else
            ways2 = cal(i + one, l, h, zero, one);
         return dp[i]=(ways1+ways2)%m;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return cal(0, low, high, zero, one);
    }
};