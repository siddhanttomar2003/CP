class Solution {
public:
    int openLock(vector<string>& d, string target) {
        queue<pair<string,int>>q;
        unordered_set<string>st(d.begin(), d.end());
        map<string,int>vis;
        if(st.find("0000") != st.end())return -1;
        q.push({"0000", 0});
        vis["0000"] = 0;
        while(q.size() > 0){
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                if(curr[i] == '0'){
                    char c = curr[i];
                    curr[i] = '9';
                    if(vis.find(curr) == vis.end() && st.find(curr) == st.end()){
                        vis[curr] = steps + 1;
                        q.push({curr, steps + 1});
                    }
                    curr[i] = '0';
                    curr[i]++;
                     if(vis.find(curr) == vis.end() && st.find(curr) == st.end()){
                        vis[curr] = steps + 1;
                        q.push({curr, steps + 1});
                    }
                    curr[i] = c;
                }
                else if(curr[i] == '9'){
                    char c = curr[i];
                    curr[i] = '0';
                    if(vis.find(curr) == vis.end() && st.find(curr) == st.end()){
                        vis[curr] = steps + 1;
                        q.push({curr, steps + 1});
                    }
                    curr[i] = '9';
                    curr[i]--;
                     if(vis.find(curr) == vis.end() && st.find(curr) == st.end()){
                        vis[curr] = steps + 1;
                        q.push({curr, steps + 1});
                    }
                    curr[i] = c;
                }
                else {
                    char c = curr[i];
                    curr[i]++;
                    if(vis.find(curr) == vis.end() && st.find(curr) == st.end()){
                        vis[curr] = steps + 1;
                        q.push({curr, steps + 1});
                    }
                    curr[i] = c;
                    curr[i]--;
                    if(vis.find(curr) == vis.end() && st.find(curr) == st.end()){
                        vis[curr] = steps + 1;
                        q.push({curr, steps + 1});
                    }
                    curr[i] = c;
                }
            }
        }
        if(vis.find(target) != vis.end())return vis[target];
        return -1; 
    }
};