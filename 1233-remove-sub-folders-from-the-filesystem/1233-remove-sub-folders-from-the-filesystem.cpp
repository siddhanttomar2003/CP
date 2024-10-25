class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        map<string, int> mp;
        for (int i = 0; i < folder.size(); i++) {
            mp[folder[i]]++;
        }
        vector<string> ans;
        for (int i = 0; i < folder.size(); i++) {
            string curr = "";
            bool check = true;
            for (int j = 0; j < folder[i].size(); j++) {
                curr += folder[i][j];
                if (folder[i][j] == '/') {
                    curr.pop_back();
                    if (mp.find(curr) != mp.end()) {
                        check = false;
                        break;
                    }
                    curr += '/';
                }
            }
            if (check)
                ans.push_back(folder[i]);
        }
        return ans;
    }
    };