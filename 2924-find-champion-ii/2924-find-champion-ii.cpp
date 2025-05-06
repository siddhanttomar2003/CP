class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        for(auto it:edges){
            indegree[it[1]]++;
        }
        set<int>st;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)st.insert(i);
        }
        if(st.size()>1 || st.size()==0)return -1;
        return *st.begin();
    }
};