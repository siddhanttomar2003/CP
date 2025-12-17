class Solution {
public:
    bool isPal(int num){
        string ans = "";
        while(num){
            ans += (char)(num % 2) + 48;
            num /= 2;
        }
        reverse(ans.begin(), ans.end());
        int i = 0, j = ans.size() - 1;
        while(i < j){
            if(ans[i] != ans[j])return false;
            i++;j--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        vector<int>pre(5001, 1e9);
        int last = 1e9;
        for(int i = 0; i <= 5000; i++){
            if(isPal(i)){
                pre[i] = 0;
                last = i;
                // cout << "Yes" << endl;
            }
            else {
                pre[i] = i - last;
                // cout << "No" << endl;
            }
        }
        last = 1e9;
        for(int i = 5000; i >= 0; i--){
            if(isPal(i))last = i;
            else pre[i] = min(pre[i], last - i);
        }
        for(int i = 0; i < n; i++){
            ans[i] = pre[nums[i]];
        }
        return ans;
    }
};