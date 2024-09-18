class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<string>> mp;

        // Custom comparator as a lambda
        auto comp = [](string a, string b) {
          return b+a>a+b;
        };

        for (int i = 0; i < nums.size(); i++) {
            string temp = to_string(nums[i]);
            int fir = temp[0] - '0'; 
            mp[fir].push_back(temp);
        }

        string ans = "";
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            vector<string> temp = it->second;
            sort(temp.begin(), temp.end(), comp);  
            for (int i = temp.size() - 1; i >= 0; i--) {
                ans += temp[i];
            }
        }
         while(ans[0]=='0' && ans.length()>1)
            ans.erase(0,1);
        return  ans;

    }
};
