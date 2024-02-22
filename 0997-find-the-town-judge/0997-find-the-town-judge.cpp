class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return 1;
        unordered_map<int,int>mp;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]=-1;
            if(mp[trust[i][1]]!=-1){
                mp[trust[i][1]]++;
            }
        }
        for(auto it:mp){
            if(it.second==n-1)return it.first;
        }
        return  -1;
    }
};