class Solution {
public:
    vector<vector<int>>adj;
    vector<int>dp;
    int dfs(int node, vector<int>&vis, int start){
        vis[node] = 1;
        int maxi = 0;
        if(dp[node] != -1  && node != start)return dp[node];
        for(auto it : adj[node]){
            if(!vis[it]){
                maxi = max(maxi, dfs(it, vis, start));
            }
        }
        vis[node] = 0;
        return dp[node] = maxi + 1;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        adj.resize(n);
        dp.resize(n, -1);
        vector<int>next(n, n), prev(n, -1);
        stack<int>st;
        for(int i = n - 1; i >= 0; i--){
            while(st.size() && arr[i] > arr[st.top()]){
                st.pop();
            }
            if(st.size())next[i] = st.top();
            st.push(i);  
        }
        while(st.size())st.pop();
        for(int i = 0; i < n; i++){
            while(st.size() && arr[i] > arr[st.top()]){
                st.pop();
            }
            if(st.size())prev[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i > j && prev[i] + 1 <= j && i - j <= d)adj[i].push_back(j);
                else if(i < j && next[i] - 1 >= j && j - i <= d)adj[i].push_back(j);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << i <<" ->";
        //     for(auto it : adj[i])cout << it << " ";
        // }
        int count = 0;

        for(int i = 0; i < n; i++){
            vector<int>vis(n, 0);
            count = max(count, dfs(i, vis, i));
            // cout << dp[i] << " ";
        }
        return count;
    }
};