class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>f_ans(n-k+1);
        for (int i = 0; i < n-k+1 ; i++) {
        map<int, int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   
            for (int j = i; j <i+k  ; j++) {

                mp[nums[j]]++;
            }
            for (auto it : mp) {
                pq.push({it.second, it.first});
            }
            while (pq.size() > x) {
                pq.pop();
            }
            int ans=0;
            while(pq.size()>0){
                ans+=(pq.top().first*pq.top().second);
                pq.pop();
            }
            f_ans[i]=ans;

        }
        return f_ans;
    }

};