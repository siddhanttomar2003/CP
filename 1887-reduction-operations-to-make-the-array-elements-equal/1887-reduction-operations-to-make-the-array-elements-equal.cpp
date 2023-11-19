class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int min_length=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])min_length++;
            else break;
        }
        int prev=1;
        int ans=0;
        for(int i=n-1;i>=min_length;i--){
                  if(nums[i]==nums[i-1])prev++;
                  else{     
                ans+=prev;
                prev++;          
        }
        }
        return ans;
    }
};