class Solution {
public:
    int myAtoi(string s) {
        bool check_dig = false;
        bool check_minus = false;
        int n = s.size();
        int i = 0;
        long long mini = -pow(2, 31);
        long long maxi = pow(2, 31) - 1;
        // trim space
        while (i < n && s[i] == ' ') {
            i++;
        }
        if(i == n)return 0;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        string ans = "";
        while (i < n) {
            if(s[i] >= 48 && s[i] <= 57){
                 ans += s[i];
                 long long temp = stoll(ans);
                 if(sign == -1)temp = -temp;
                 if(temp < mini)return mini;
                 if(temp > maxi)return maxi;
                 i++;
            }
            else break;
        }
        if(ans.size() == 0)return 0;
        long long f_ans = stoll(ans);
        if(sign == -1)f_ans = -f_ans;
        return f_ans;
    }
};