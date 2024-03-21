class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int len=0;
        unordered_map<char,int>mp;
        while(j<s.length()){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]++;
                 len=max(len,j-i+1);
                j++;       
            }
            else{
              while(s[i]!=s[j]){
                mp.erase(s[i]);
                i++;
              }
              mp.erase(s[i]);
              i++;
              mp[s[j]]++;
              j++;
            }
        }
        return len;
    }
};