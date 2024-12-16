typedef pair<int,int> pi;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pi, vector<pi>,greater<pi>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int ind=pq.top().second;
            int num=pq.top().first;
            pq.pop();
            num*=multiplier;
            pq.push({num,ind});
        }
        int n=nums.size();
        vector<int>ans(n);
        while(pq.size()>0){
            int ind=pq.top().second;
            int num=pq.top().first;
            ans[ind]=num;
            pq.pop();
        }
        return ans;
    }
};