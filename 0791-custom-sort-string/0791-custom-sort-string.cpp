class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<order.length();i++){
            mp[order[i]]=i+1;
        }
        string extra="";
        vector<pair<int,char>>v;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                v.push_back({mp[s[i]],s[i]});
            }
            else extra+=s[i];
        }
        sort(v.begin(),v.end());
        string ans="";
        for(int i=0;i<v.size();i++){
            ans+=v[i].second;
        }
        ans+=extra;
        return ans;
    }
};