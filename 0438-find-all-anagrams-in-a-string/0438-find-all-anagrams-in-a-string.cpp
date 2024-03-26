class Solution {
public:
    bool check(vector<int> &sv,vector<int> &pv){
        for(int i=0;i<26;i++){
            if(sv[i]!=pv[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.length()>s.length())return {};
        int k=p.length();
        vector<int> pv(26,0);
        for(int i=0;i<k;i++){
            pv[p[i]-'a']++;
        }
        vector<int> sv(26,0);
        int i=0;int j=0;
        for(j=0;j<k;j++){
          sv[s[j]-'a']++;
        }
        j--;
      while(j<s.length()-1){
         if(check(sv,pv)) ans.push_back(i);
         sv[s[i]-'a']--;
         i++;j++;
         sv[s[j]-'a']++;      
      }
      if(check(sv,pv))ans.push_back(i);
      return ans;
    }
};