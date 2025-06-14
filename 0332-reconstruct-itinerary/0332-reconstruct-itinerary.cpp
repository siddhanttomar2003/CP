class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        for(auto it:tickets){
            adj[it[0]].insert(it[1]);
        }
        stack<string>euler;
        vector<string>ans;
        euler.push("JFK");
        while(!euler.empty()){
            string a=euler.top();
            if(adj[a].size()==0){// means dead end need to come at last in ans
                ans.push_back(a);
                euler.pop();
            }
            else {
                // taking out the best path 
                auto des=adj[a].begin();
                euler.push(*des);
                adj[a].erase(des);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};