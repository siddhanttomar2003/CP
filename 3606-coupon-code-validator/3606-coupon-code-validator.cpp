class Solution {
public:
    bool check(string &a, string &b, map<string, int> &mp){
        if(a.size() == 0 || mp.find(b) == mp.end())return false;
        for(int i = 0; i < a.size(); i++){
            if(a[i] >= 48 && a[i] <= 57 || a[i] >= 97 && a[i] <= 122 || a[i] >= 65 && a[i] <= 90 || a[i] == '_')continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, int>mp;
        mp["electronics"] = 1;
        mp["grocery"] = 2;
        mp["pharmacy"] = 3;
        mp["restaurant"] = 4;
        vector<int> ans;
        int n = code.size();
        for(int i = 0; i < n; i++){
            if(check(code[i], businessLine[i], mp) && isActive[i])ans.push_back(i);
        }
        // cout << mp[code[0]] << " " << mp[code[1]] << endl;
        sort(ans.begin(), ans.end(), [&mp, &businessLine, &code](int a, int b){
            if(mp[businessLine[a]] != mp[businessLine[b]])return mp[businessLine[a]] < mp[businessLine[b]];
            return code[a] < code[b];
        });
        vector<string> f_ans;
        for(int i = 0; i < ans.size(); i++)f_ans.push_back(code[ans[i]]);
        return f_ans;
    }
};