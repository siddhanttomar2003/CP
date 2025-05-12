typedef long long ll;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<ll,ll>mp,mini;
        ll pre=0;
        ll ans=-1e18;
        bool check=false;
        for(int i=0;i<n;i++){
          ll req1=nums[i]-k*1ll;
          ll req2=nums[i]+k*1ll;
          pre+=nums[i]*1ll;
          if(mp.find(req1)!=mp.end()){
              check=true;
              ans=max(ans,pre-(mini[req1]-req1));
          }  
           if(mp.find(req2)!=mp.end()){
               check=true;
              ans=max(ans,pre-(mini[req2]-req2));
          } 
          if(mini.find(nums[i])==mini.end())mini[nums[i]]=pre;
          else mini[nums[i]]=min(mini[nums[i]],pre);
          mp[nums[i]]++;
        }
        if(check)return ans;
        return 0;
    }
};