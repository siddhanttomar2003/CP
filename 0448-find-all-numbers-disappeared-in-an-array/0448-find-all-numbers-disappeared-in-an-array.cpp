class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // using hashmap
        int n=nums.size();
    //     unordered_set<int>s;
    //     for(int i=0;i<n;i++){
    //               s.insert(nums[i]);
    //     }
    //     int num=1;
    //     vector<int>ans;
    //    for(int i=1;i<=n;i++){
    //         if(s.find(i)==s.end())ans.push_back(i);
    //    }
    //    return ans;
    // now using cyclic sort
     for(int i=0;i<n;i++){
        if(nums[i]!=i-1){
            if(nums[nums[i]-1]==nums[i])continue;
            else {swap(nums[nums[i]-1],nums[i]);i--;}
        }
     }
     vector<int>Ans;
     for(int i=0;i<n;i++){
        if(nums[i]!=i+1)Ans.push_back(i+1);
     }
     return Ans;
    }
};