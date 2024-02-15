class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int i=0; int e=numbers.size()-1;
        while(i<e){
            int sum=numbers[i]+numbers[e];
            if(sum==target){
                ans.push_back(i+1);
                ans.push_back(e+1);
                break;
            }
            else if(sum<target)i++;
            else e--;
        }
        return ans;
    }
};