class Solution {
public:
    int kedane(int pos, int neg, vector<int>nums,int freq){
        int ansi=0;
        int curr=0;
        int curr_s=0,curr_e=0;
        int s=0,e=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==pos)nums[i]=1;
          else if(nums[i]==neg)nums[i]=-1;
          else nums[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr>ansi){
                curr_e=i;
                ansi=curr;
                s=curr_s;
                e=curr_e;
            }
            if(curr<=0){
                curr=0;
                curr_s=i+1;
                curr_e=i+1;
            }
            else {
                curr_e=i;
            }
        }
        cout<<ansi<<endl;
        int count_pos=0;
        for(int i=s;i<=e;i++)if(nums[i]==-1)count_pos++;
        return ansi+freq-count_pos;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        int ans=0;
        int count=0;
        if(mp.find(k)!=mp.end()){
            count=mp[k];
            mp.erase(k);
        }
        for(auto it:mp){
            
          ans=max(ans , kedane(it.first,k,nums,count));
            
        }
        return ans;
    }
};