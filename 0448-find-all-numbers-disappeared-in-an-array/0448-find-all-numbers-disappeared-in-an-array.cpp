class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // using hashmap
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
                  s.insert(nums[i]);
        }
        int num=1;
        vector<int>ans;
       for(int i=1;i<=n;i++){
            if(s.find(i)==s.end())ans.push_back(i);
       }
       return ans;
    }
};