class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        int poseven=0;
        int posodd=1;
        for(int i=0;i<n;i++){
           if(nums[i]>0){
               v[poseven]=nums[i];
               poseven+=2;
           }
           else {
               v[posodd]=nums[i];
               posodd+=2;
           }
        }
        return v;
    }
};