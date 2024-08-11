class Solution {
public:
    void cal(string& curr, vector<string>& ans, int n) {
        if (curr.size() == n){
            ans.push_back(curr);
            return ;
        }
        if (curr.size() == 0) {
            curr += '0';
            cal(curr, ans, n);
            curr.pop_back();
            curr += '1';
            cal(curr, ans, n);
        } else {
            if (curr.back() == '1') {
                  curr+='0';
                cal(curr, ans, n);
                curr.pop_back();
            }
                curr+='1';
                cal(curr,ans,n);
                curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr="";
        cal(curr, ans, n);
        return ans;
    }
};