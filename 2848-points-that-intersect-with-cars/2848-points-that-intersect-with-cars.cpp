class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>temp(102,0);
        for(int i=0;i<nums.size();i++){
            temp[nums[i][0]]++;
            temp[nums[i][1]+1]--;
        }
        for(int i=1;i<101;i++){
            temp[i]+=temp[i-1];
        }
        int count=0;
        for(int i=1;i<101;i++){
            if(temp[i]>0)count++;
        }
        return count;
    }
};