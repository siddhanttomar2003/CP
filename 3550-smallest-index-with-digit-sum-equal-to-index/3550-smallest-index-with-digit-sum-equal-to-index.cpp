class Solution {
public:
    bool check(int a , int b)
    {
        int sum=0;
        while(b>0){
            sum+=b%10;
            b/=10;
        }
        return sum==a;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(check(i,nums[i]))return i;
        }
        return -1;
    }
};