typedef long long ll;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        if(n==2){
            return max({nums[0]+nums[1],(nums[0]^k)+(nums[1]^k)});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        for(int i=0;i<nums.size();i++){
            if((nums[i]^k)>nums[i]){
                pq.push({((ll)nums[i]^k),(ll)i});
            }
        }
        int index=-1;
        vector<int>vis(n,0);
        if(pq.size()&1){
            index=pq.top().second;
            vis[index]=1;
            pq.pop();
        }
        ll sum=0;
        while(pq.size()>0){
            sum+=pq.top().first;
            vis[pq.top().second]=1;
            pq.pop();
        }
        if(index!=-1){
        ll mini=1e10;
        int index2=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                 ll tradeoff=nums[i]-(nums[i]^k);
                 if(tradeoff<mini){
                    mini=tradeoff;
                    index2=i;
                 }
            }
        }
        ll plus=(nums[index]^k)-nums[index];
        if(plus>mini){
            vis[index2]=1;
            sum+=(nums[index]^k)+(nums[index2]^k);
        }
        else {
            vis[index2]=1;
            sum+=(nums[index])+(nums[index2]);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i])sum+=nums[i];
        }
        
        return sum;

    }
};