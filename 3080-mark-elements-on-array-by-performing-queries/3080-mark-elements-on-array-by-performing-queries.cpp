class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > q;
        long long curr=0;
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
            curr+=nums[i];
        }
        int prev=0;
        vector<long long >ans;
        for(int i=0;i<queries.size();i++){
            if(nums[queries[i][0]]!=-1)curr-=nums[queries[i][0]];
         nums[queries[i][0]]=-1;
        
          int a=0;
          while(a!=queries[i][1]&& q.size()
          >0){
          if(nums[q.top().second]!=-1){
            a++;
            curr-=nums[q.top().second];
            nums[q.top().second]=-1;
            q.pop();
          }
          else {
            q.pop();
          }
          }
         
           ans.push_back(curr);
        }
        return ans;
    }
};