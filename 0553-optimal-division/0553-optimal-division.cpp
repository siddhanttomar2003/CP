class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans="";
        ans+=to_string(nums[0]);
        if(nums.size()==2){
            ans+='/';
            ans+=to_string(nums[1]);
            return ans;
        }
        for(int i=1;i<nums.size();i++){
          ans+='/';
          if(i==1)ans+='(';
          ans+=to_string(nums[i]);
          if(i==nums.size()-1)ans+=')';
        }
        return ans;
    }
};