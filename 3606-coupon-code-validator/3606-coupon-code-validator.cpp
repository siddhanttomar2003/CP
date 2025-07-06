class Solution {
public:
    bool isValid(string & s){
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57) || s[i] == '_' )continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string,int>mp;
        mp["electronics"] = 1;
        mp["grocery"] = 2;
        mp["pharmacy"] = 3;
        mp["restaurant"] = 4;
        vector<vector<string>>arr;
        for(int i = 0; i < code.size(); i++){
            if(code[i].size() > 0 && mp.find(businessLine[i]) != mp.end() && isActive[i] &&  isValid(code[i])){
                arr.push_back({code[i], businessLine[i]});
            }
        }
        sort(arr.begin(), arr.end(), [&mp](vector<string> & a, vector<string> &b){
                if(a[1] != b[1])return mp[a[1]] < mp[b[1]];
                return mp[a[0]] < mp[b[0]];
        });
        vector<string>ans;
        for(auto it : arr)ans.push_back(it[0]);
        return ans;
    }
};