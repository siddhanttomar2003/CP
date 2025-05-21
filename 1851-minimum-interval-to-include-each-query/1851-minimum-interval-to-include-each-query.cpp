class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
             if(a[1]-a[0]+1!=b[1]-b[0]+1)return a[1]-a[0]+1<b[1]-b[0]+1;
             return a[0]<b[0];
        });
        set<int>q(queries.begin(),queries.end());
        map<int,int>ans;
        for(auto it:intervals)
        {
            int s=it[0];
            int lim=it[1];
            auto it2=q.lower_bound(s);
            while(it2!=q.end()){
                auto it3=next(it2);
                if(*it2<=lim){
                    ans[*it2]=(lim-s+1);
                }
                else break;
                q.erase(*it2);
                it2=it3;
            }
        }
        vector<int>f;
        for(int i=0;i<queries.size();i++){
            if(ans.find(queries[i])!=ans.end()){
                f.push_back(ans[queries[i]]);
            }
            else f.push_back(-1);
        }
        return f;
    }
};