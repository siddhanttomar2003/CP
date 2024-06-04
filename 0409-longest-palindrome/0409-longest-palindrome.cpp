class Solution {
public:
    int longestPalindrome(string s) {
        int count=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        int odd=0;
        for(auto it:mp){
            if(it.second&1){
                odd=1;
                count+=it.second-1;
            }
            else count+=it.second;
        }
        if(odd==1)count++;
        return count;
    }
};