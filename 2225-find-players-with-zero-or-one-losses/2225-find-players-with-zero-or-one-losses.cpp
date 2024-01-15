class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int>s;
        unordered_map<int,int>losers;
        for(int i=0;i<matches.size();i++){
            for(int j=0;j<2;j++){
             s.insert(matches[i][j]);
             if(j==1){losers[matches[i][j]]++;}
            }
        }
        vector<vector<int>>ans;
        vector<int>winners;vector<int>loosers;
        for(auto it:s){
            if(losers.find(it)==losers.end())winners.push_back(it);
            else {
                if(losers[it]==1)loosers.push_back(it);
            }
        }
        sort(winners.begin(),winners.end());
        sort(loosers.begin(),loosers.end());
        ans.push_back(winners);
        ans.push_back(loosers);
        return ans;
    }
};