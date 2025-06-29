class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int n = num.size();
        for(int i = n - 1; i >= 0; i--){
            int curr = num[i] - 48;
            if(curr & 1){
                while(i >= 0){
                    ans += num[i];
                    i--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};