class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int,int>mp;
        int count = 0;
        for(auto it : s)mp[it]++;
        for(auto it : g){
            int req = it;
            auto it2 = mp.lower_bound(it);
            if(it2 != mp.end()){
                mp[it2->second]--;
                if(mp[it2->second] == 0)mp.erase(it2->first);
                count++;
            }
        }
        return count;
    }
};