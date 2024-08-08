class Solution {
public:
     bool check(vector<int>&temp1, vector<int> &temp2){
        if(temp1[0]==temp2[0])return true;
        if(temp1[1]==temp2[1])return true;
        return false;
     }
     void dfs(int curr, vector<vector<int>> & stones, vector<int> &is_visited){
        is_visited[curr]=1;
        for(int i=0;i<stones.size();i++){
            if(check(stones[curr],stones[i]) && !is_visited[i]){
                dfs(i,stones,is_visited);
            }
        }
     }
    int removeStones(vector<vector<int>>& stones) {
        // using dfs;
        int n=stones.size();
        vector<int>is_visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
             if(!is_visited[i]){
                count++;
                dfs(i,stones,is_visited);
             }
        }
        return n-count;
    }
};