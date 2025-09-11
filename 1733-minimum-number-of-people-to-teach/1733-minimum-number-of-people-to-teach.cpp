class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
        int mini = 1e9;
        set<pair<int,int>>st;
        map<int,map<int,int>>lan;
        int m = l.size();
        for(int i = 1; i <= m; i++){
            for(auto it : l[i - 1])lan[i][it]++;
        }
        for(auto it : f){
            int u = it[0];
            int v = it[1];
            map<int,int>mp;
            bool check = false;
            for(auto it2 : l[u - 1])mp[it2]++;
            for(auto it2 : l[v - 1]){
                mp[it2]++;
                if(mp[it2] == 2)check = true;
            }
            if(!check)st.insert({u, v});
        }
        for(int i = 1; i <= n; i++){
            int count = 0;
            for(auto it : f){
                if(st.find({it[0], it[1]}) != st.end()){
                    if(lan[it[0]].find(i) == lan[it[0]].end()){
                        count++;
                        lan[it[0]][i]++;
                    }
                    if(lan[it[1]].find(i) == lan[it[1]].end()){
                        count++;
                        lan[it[1]][i]++;
                    }
                }
            }
            mini = min(mini, count);
        }
        return mini;
    }
};