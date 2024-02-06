class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>mp;
       for(int i=0;i<strs.size();i++){
           string a=strs[i];
           sort(a.begin(),a.end());
           mp[a].push_back(strs[i]);
       }
       vector<vector<string>>s;
       for(auto it:mp){
           s.push_back(it.second);
       }
       return s;
    }
};