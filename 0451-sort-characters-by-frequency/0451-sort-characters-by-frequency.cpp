class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it:s)mp[it]++;
        sort(s.begin(),s.end(),[&mp](char a, char b){
             if(mp[a]>mp[b])return true;
             return false;
        }); 
        return s;
    }

};