#define M 1000000007
typedef long long ll;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<ll>freq(1e5+1,0);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        for(int i=0;i<requests.size();i++){
            freq[requests[i][0]]++;
            freq[requests[i][1]+1]--;
        }
        pq.push(freq[0]);
        for(int i=1;i<1e5+1;i++){
            freq[i]+=freq[i-1];
            pq.push(freq[i]);
        }

        while(pq.size()>n){
             pq.pop();
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++){
           ans=(ans+((pq.top()*nums[i])%M))%M;
           pq.pop();
        } 
        return ans;
    }
};