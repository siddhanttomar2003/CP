class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int ele=-1,freq=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           if(nums[i]==ele){
            freq++;
           }
           else freq--;
           if(freq<0){
            freq=0;
            ele=nums[i];
           }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ele==nums[i])count++;
        }
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+(nums[i]==ele?1:0);
            int curr=pre[i+1];
            int curr_len=i+1;
            int rem_len=n-(i+1);
            int rem=count-pre[i+1];
            if(curr*2>curr_len && rem*2>rem_len)return i;
        }
        return -1;
        
    }
};