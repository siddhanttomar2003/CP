class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        int n=names.size();
        for(int i=0;i<n;i++){
            pq.push({heights[i],names[i]});
        }
        vector<string>ans;
        while(pq.size()>0){
             ans.push_back(pq.top().second);
             pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};