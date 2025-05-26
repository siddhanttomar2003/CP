class Solution {
public:
  
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        int first_node=-1;
        vector<array<int,26>>dp(n);
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0){
                q.push(i);
                if(first_node == -1)first_node = i;
                dp[i][colors[i]-97]=1;
            }
        }
        int size = 0;
        int maxi = 1;        
        while (q.size() > 0) {
            size++;
            int par = q.front();
            q.pop();
            for (auto it : adj[par]) {
                indegree[it]--;
                for(int i = 0; i < 26; i++){
                    dp[it][i]=max(dp[it][i],dp[par][i]);
                }
                if (indegree[it] == 0){
                    int curr = ++dp[it][colors[it]-97];
                    maxi=max(maxi,curr);
                    q.push(it);
                }
            }
        }
        if (size != n)
            return -1;
        
        return maxi;
    }
};