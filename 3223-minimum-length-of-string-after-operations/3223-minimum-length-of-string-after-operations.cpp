class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int del=0;
        map<char,int>mp;
        for(int i=0;i<n;i++)mp[s[i]]++;
        for(auto it:mp){
            del+=((it.second-1)/2)*2;
        }
        return n-del;
    }
};