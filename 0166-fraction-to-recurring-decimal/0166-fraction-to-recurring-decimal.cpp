class Solution {
public:
    string fractionToDecimal(int n, int d) {
        bool minus = false;
        if(n < 0 && d > 0)minus = true;
        else if(n > 0 && d < 0)minus = true;
        string ans = "";
        if(minus) ans += '-';
        double temp = (double)n / (double)d;
        string a = to_string(temp);

        if(n % d == 0)return to_string(n / d);
        ans += to_string(n / d);
        string curr = "";
        string ans2 = "";
        vector<int>freq(10, 0);
        for(int i = 2; i < a.size(); i++){
            freq[a[i] - 48]++;
            if(freq[a[i] - 48] == 2){
                ans2 = curr;
                break;
            }
            curr += a[i];
        }
        if(ans2.size() == 0)ans2 = curr;
        if(ans2.back() == '0'){
            ans2.pop_back();
            return ans + '.' + ans2;
        }
        ans += '.';
        bool check = false;
        for(int i = 2; i < a.size(); i++){
            if(freq[a[i] - 48] == 2 && check)break;
            if(freq[a[i] - 48] == 2 && !check){
                ans += '(';
                check = true;
            }
            ans += a[i];
        }
        ans += ')';
        return ans;
    }
};