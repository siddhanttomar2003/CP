class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos=-1;
        // we need to find the out the break point from the reverse
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
             pos=i-1;
             break;
            }
        }
        if(pos==-1){reverse(nums.begin(),nums.end());
        for(int j=0;j<nums.size();j++){
            cout<<nums[j]<<" ";
        }
        }
        else {
        int i=nums.size()-1;
        while(pos<i){
            if(nums[i]>nums[pos]){
                swap(nums[pos],nums[i]);
                break;
            }
            i--;
        }
        reverse(nums.begin()+pos+1,nums.end());
         for(int j=0;j<nums.size();j++){
             cout<<nums[j]<<" ";
         }
        }
    }
};