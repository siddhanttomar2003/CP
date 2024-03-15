class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix;
        vector<int>suffix;
        int p=1;
        int s=1;
        int n=nums.size();
         for(int i=0;i<nums.size();i++){
            p*=nums[i];
            s*=nums[n-i-1];
            prefix.push_back(p);suffix.push_back(s);
         }
         for(int i=0;i<nums.size();i++){
            if(i==0){
                nums[i]=suffix[n-i-2];
            }
            else if(i==n-1){
                nums[i]=prefix[i-1];
            }
            else nums[i]=prefix[i-1]*suffix[n-i-2];
         }
         return nums;
      

    }
};