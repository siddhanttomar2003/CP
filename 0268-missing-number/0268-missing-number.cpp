class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int hash[100000]={0};
     for(int i=0;i<nums.size();i++){
         hash[nums[i]]++;
     }
     int pos=-1;
     for(int i=0;i<nums.size()+1;i++){
         if(hash[i]==0){
             pos=i;
             break;
         }
     }
     return pos;
    }
};