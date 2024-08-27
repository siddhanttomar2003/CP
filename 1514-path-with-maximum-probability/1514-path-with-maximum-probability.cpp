class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        double ans = 0;
        priority_queue<pair<double, int>> pq;
        vector<double> dis(n, 0);
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u,wt});
        }
        pq.push({1.0, start_node});
        dis[start_node]=1.0;
        while (pq.size() > 0) {
            int parent = pq.top().second;
            double curr_prob = pq.top().first;
            pq.pop();
            for (int i = 0; i < adj[parent].size(); i++) {
                int child = adj[parent][i].first;
                double  child_prob= adj[parent][i].second;
                double new_prob=child_prob*curr_prob;
                if(dis[child]<new_prob){
                    dis[child]=new_prob;
                    pq.push({dis[child],child});
                }
            }

        }
        return dis[end_node];
    }
};