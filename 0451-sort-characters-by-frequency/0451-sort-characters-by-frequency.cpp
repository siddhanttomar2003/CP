class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
          vector<pair<int,char>>v;
        for(auto it:mp){
          pair<int,char>p;
          p.first=it.second;
          p.second=it.first;
          v.push_back(p);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string a="";
        int j=0;
        while(a.length()!=s.length()){
          for(int i=0;i<v[j].first;i++){
              a+=v[j].second;
          }
          j++;

        }
        
       return a;
    }
};