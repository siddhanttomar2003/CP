class Solution {
public:  
      int reverse(int a){
        int ans=0;
        while(a>0){
            int mod=a%10;
            ans=ans*10+mod;
            a/=10;
        }
        return ans;
      }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            nums[i]=reverse(nums[i]);
            s.insert(nums[i]);
        }
        return s.size();
       
    }
};