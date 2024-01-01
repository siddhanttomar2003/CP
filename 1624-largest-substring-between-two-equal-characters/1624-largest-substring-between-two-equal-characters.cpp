class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.length();i++){
           mp[s[i]].push_back(i);
        }
        int ans=-1;
        int count=0;
        for(auto it:mp){
            if(it.second.size()>1){
              count=it.second[it.second.size()-1]-it.second[0]-1;
              ans=max(ans,count);
               
            }
        }
        return ans;
    }
};