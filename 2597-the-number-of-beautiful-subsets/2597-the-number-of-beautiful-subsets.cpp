 unordered_map<int,int>st;
class Solution {
public:
   int find_ans(vector<int>&nums,int k,int i){
     if(i<0)return 1;
    int take=0;
    int nottake=0;
      st[nums[i]]++;
    if(st[nums[i]+k]==0){
        take=find_ans(nums,k,i-1);
    }
        st[nums[i]]--;
       
        nottake=find_ans(nums,k,i-1);
    
    return take+nottake;

   }
    int beautifulSubsets(vector<int>& nums, int k) {
        // first using recursion
       
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
       return  find_ans(nums,k,n)-1;
    }
};