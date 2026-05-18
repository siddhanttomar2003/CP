class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int>dis(n, 1e9);
        queue<pair<int, int>>q;
        map<int, vector<int>>adj;
        for(int i = 0; i < n; i++){
            adj[arr[i]].push_back(i);
        }
        q.push({0, 0});
        while(q.size()){
            auto it = q.front();
            q.pop();
            int idx = it.first;
            int steps = it.second;
            dis[idx] = steps;
            if(idx + 1 < n && dis[idx + 1] > 1 + steps){
                q.push({idx + 1, 1 + steps});
            }
            if(idx - 1 >= 0 && dis[idx - 1] > 1 + steps){
                q.push({idx - 1, 1 + steps});
            }
            int ele = arr[idx];
            for(auto it : adj[ele]){
                if(it != idx){
                    if(dis[it] > 1 + steps){
                        q.push({it, 1 + steps});
                    }
                    else break;
                }
            }
            if(dis[n - 1] != 1e9)return dis[n - 1];
        }
        return -1;
    }
};