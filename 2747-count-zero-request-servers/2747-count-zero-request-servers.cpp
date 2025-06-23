class Solution {
public:
    
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;

        for(auto it:logs){
            mp[it[0]].push_back(it[1]);
            
        }
        map<int,int>line_sweep;
        for(auto it:mp){
            int curr_max = 0;
            vector<int>&temp=it.second;
            sort(temp.begin(),temp.end());
            for(auto it2: temp){
                if(it2 > curr_max){
                    line_sweep[it2]++;
                    int ma = min(1000000,it2 + x);
                    line_sweep[ma + 1]--;
                    curr_max = it2 + x;
                }
                else {
                    int e = it2 + x;
                    line_sweep[curr_max + 1]++;
                    line_sweep[e + 1]--;
                    curr_max = e;
                }
            }
        }
        vector<pair<int,int>>q;
        int size = queries.size();
        vector<int>ans(size,n);
        for(int i = 0 ; i < size; i++){
            q.push_back({queries[i],i});
        }

        sort(q.begin(),q.end());
        int j = 0;
        int curr = 0;
        for(auto it: line_sweep){
               while( j<size && q[j].first<it.first){
                  ans[q[j].second] = n-curr;
                  j++;
               }
               curr +=it.second;
        }
        return ans;
    }
};