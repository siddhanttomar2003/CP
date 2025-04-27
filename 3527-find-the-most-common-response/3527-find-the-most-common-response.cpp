class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int>mp;
        for(auto it:responses){
            set<string>st;
            for(auto it2:it){
                st.insert(it2);
            }
            for(auto it2:st){
                mp[it2]++;
            }
        }
        int maxi=0;
        string ans="";
        for(auto it:mp){
            if(it.second>maxi){
                ans=it.first;
                maxi=it.second;
            }
        }
        return ans;
    }
};