class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        vector<int>temp;
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(temp.size()==0)temp.push_back(nums[i]-k);
            else {
               int next_avail=temp.back()+1;
              if(next_avail>=nums[i]-k && next_avail<=nums[i]+k){
                temp.push_back(next_avail);
              }
              else if(next_avail<nums[i]-k)temp.push_back(nums[i]-k);
            }
        }
        return temp.size();

    }
};