class Solution {
public:
    void del(set<int>&st, int s, int e){
        cout<<s<<" "<<e<<endl;
        for(int i=s;i<=e;i++){
            st.erase(i);
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(i);
        }
        for(int i=0;i<queries.size();i++){
            int s=queries[i][0];
            int e=queries[i][1];
            auto it1=st.upper_bound(s);
            auto it2=st.lower_bound(e);
            auto it3=prev(it2);
            // cout<<*it1<<" "<<*it3<<endl;
            del(st,*it1,*it3);
            ans.push_back(st.size()-1);
        }
        return ans;
    }
};