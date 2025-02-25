class Solution {
public:
    string decToBinary(int n) {
        string s = "";
        int i = 0;
        while (n > 0) {
            s = to_string(n % 2) + s;
            n = n / 2;
            i++;
        }
        return s;
    }
    int binaryToDecimal(string n) {
        string num = n;
        int dec_value = 0;
        int base = 1;
        int len = num.length();
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1')
                dec_value += base;
            base = base * 2;
        }
        return dec_value;
    }
    void cal(string& ans, int n, int i, set<string>& st, string curr) {
        if (i == n) {
            if (st.find(curr) == st.end()) {
                ans = curr;
            }
            return;
        }
        curr += '0';
        cal(ans, n, i + 1, st, curr);
        curr.pop_back();
        curr += '1';
        cal(ans, n, i + 1, st, curr);
        curr.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        string ans = "";
        string curr = "";
        int n=nums.size();
        cal(ans, n , 0, st, curr);
        return ans;
    }
};