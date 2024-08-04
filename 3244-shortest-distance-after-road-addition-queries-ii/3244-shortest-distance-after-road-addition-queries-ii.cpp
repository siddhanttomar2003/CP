class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(i);
        }
        for(int i=0;i<queries.size();i++){
            int s=queries[i][0];
            int e=queries[i][1];
            auto it=st.lower_bound(s);
            auto it2=st.upper_bound(e-2);
            st.erase(it,it2);
            ans.push_back(st.size()-1);
        }
        return ans;
    }
};