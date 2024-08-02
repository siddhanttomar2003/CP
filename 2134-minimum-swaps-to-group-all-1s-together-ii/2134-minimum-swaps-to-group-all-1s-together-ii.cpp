class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)count1++;
        }
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        int i=0;int j=0;
        int curr=0;
         int maxi=0;
         int nn=nums.size();
          for(j=0;j<count1;j++){
            if(nums[j]==1)curr++;
          }
          j--;
          maxi=max(maxi,curr);
         while(j+1<nn){
              j++;
              if(nums[j]==1)curr++;
              if(nums[i]==1)curr--;
              i++;
              maxi=max(maxi,curr);
         }
         return count1-maxi;

    }
};