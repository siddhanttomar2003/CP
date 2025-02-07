class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        map<int,int>b_c;
        map<int,int>c_b;
        for(int i=0;i<queries.size();i++){
            int b=queries[i][0];
            int c=queries[i][1];
            if(b_c.find(b)!=b_c.end()){
                c_b[b_c[b]]--;
                if(c_b[b_c[b]]==0)c_b.erase(b_c[b]);
            }
            c_b[c]++;
            b_c[b]=c;
            ans.push_back(c_b.size());
        }
        return ans;
    }
};