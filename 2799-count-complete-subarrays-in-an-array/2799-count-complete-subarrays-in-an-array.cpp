class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
      int count=0;
      set<int>st(nums.begin(),nums.end());
      int size=st.size();
      int n=nums.size();
      int maxi=*max_element(nums.begin(),nums.end());
      for(int i=0;i<n;i++){
        vector<int>vis(maxi+1,0);
        int c=0;
        for(int j=i;j<n;j++){
           if(!vis[nums[j]]){
            c++;
            vis[nums[j]]=1;
           }
           if(c==size)count++;
        }
      }
      return count;
    }
};