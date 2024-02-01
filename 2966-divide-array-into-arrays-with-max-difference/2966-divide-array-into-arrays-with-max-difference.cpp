class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        bool flag=true;
        for(int i=0;i<nums.size()-2;i+=3){
         if(nums[i+1]-nums[i]>k||nums[i+2]-nums[i]>k){
             flag=false;
             break;
         }
        }
        vector<int>v;
        if(flag){
             for(int i=0;i<nums.size();i++){
                 v.push_back(nums[i]);
                 if(i%3==2){
                     ans.push_back(v);
                     v.clear();
                 }
             }
             return ans;
        }
        else return ans;
    }
};