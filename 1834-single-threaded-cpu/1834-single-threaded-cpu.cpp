class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        map<vector<int>,int>mp;
        for(int i = 0; i < tasks.size(); i++){
            mp[tasks[i]] = i;
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int curr = tasks[0][0];
        int n = tasks.size();
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(tasks[i][0] <= curr){
                pq.push({tasks[i][1], mp[tasks[i]]});
            }
            else {
                while(curr < tasks[i][0] && !pq.empty()){
                    curr += pq.top()[0];
                    int id = pq.top()[1];
                    ans.push_back(id);
                    pq.pop();
                }
                if(curr < tasks[i][0]){
                    curr = tasks[i][1] + tasks[i][0];
                    ans.push_back(mp[tasks[i]]);
                }
                else {
                pq.push({tasks[i][1], mp[tasks[i]]});
                }
            }
            // cout << curr << endl;
        }
        while(!pq.empty()){
            int id = pq.top()[1];
            pq.pop();
            ans.push_back(id);
        }
        return ans;
    }
};