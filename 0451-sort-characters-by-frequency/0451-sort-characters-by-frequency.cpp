class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>v;
        map<char,int>mp;
        for(auto it:s)mp[it]++;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        string ans="";
        for(auto it:v){
            int times=it.first;
            for(int i=0;i<times;i++){
                ans+=it.second;
            }
        }
        return ans;
    }

};