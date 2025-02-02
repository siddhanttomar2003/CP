class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<int>odd,even;
        for(auto it:mp){
            if(it.second&1)odd.push_back(it.second);
            else even.push_back(it.second);
        }
        sort(even.begin(),even.end());sort(odd.begin(),odd.end());
        int s1=even.size();int s2=odd.size();

        return odd[s2-1]-even[0];
    }
};