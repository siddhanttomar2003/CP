class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // using moore voting algo
        int count1=0;int count2=0;
        int el1,el2;
        for(int i=0;i<nums.size();i++){
              if(el1==nums[i]){
                count1++;
            }
             else if(el2==nums[i])count2++;
          else  if(count1==0){
                el1=nums[i];
                count1++;
            }
            else if(count2==0 && nums[i]!=el1){
                el2=nums[i];
                count2++;
            }
          
           
            else {
                count1--;count2--;
            }
        }
        int check1=0;int check2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1)check1++;
            else if(nums[i]==el2)check2++;
        }
        vector<int>ans;
        if(check1>nums.size()/3)ans.push_back(el1);
        if(check2>nums.size()/3)ans.push_back(el2);
        return ans;
    }
};