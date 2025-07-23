class Solution {
public:
    int dp1[1001][3];
    int dp2[1001][3];
    int cal1(int f, int s, int i, int state, vector<int> &pre, int n){
        if(state == 2)return 0;
        if(i == n){
            if(state == 2)return 0;
            else return -1e9;
        }
        if(dp1[i][state] != -1)return dp1[i][state];
        int ans = 0;
        if(state == 0){
            if(i + f <= n)
            ans = pre[i + f] - pre[i] + cal1(f, s, i + f, 1, pre, n);
            ans =  max(ans, cal1(f, s, i + 1, 0, pre, n));
        }
        else if(state == 1){
            if(i + s <= n)
            ans = pre[i + s] - pre[i] + cal1(f, s, i + s, 2, pre, n);
            ans = max(ans, cal1(f, s, i + 1, 1, pre, n));
        }
        return dp1[i][state] = ans;
    }
    int cal2(int s, int f, int i, int state, vector<int> &pre, int n){
        if(state == 2)return 0;
        if(i == n){
            if(state == 2)return 0;
            else return -1e9;
        }
        if(dp2[i][state] != -1)return dp2[i][state];
        int ans = 0;
        if(state == 0){
            if(i + s <= n)
            ans = pre[i + s] - pre[i] + cal2(s, f, i + s, 1, pre, n);
            ans =  max(ans, cal2(s, f, i + 1, 0, pre, n));
        }
        else if(state == 1){
            if(i + f <= n)
            ans = pre[i + f] - pre[i] + cal2(s, f, i + f, 2, pre, n);
            ans = max(ans, cal2(s, f, i + 1, 1, pre, n));
        }
        return dp2[i][state] = ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        vector<int>pre(n + 1, 0);

        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + nums[i]; 
        }

        return max(cal1(firstLen, secondLen, 0, 0, pre, n), cal2(secondLen, firstLen, 0, 0, pre, n));
    }
};