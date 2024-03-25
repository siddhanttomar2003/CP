class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int count0=0;
        int len=0;
        while(j<nums.size()){
            if(count0<k){
                if(nums[j]==1){
                    len=max(len,j-i+1);
                    j++;
                }
                else{
                    count0++;
                    len=max(len,j-i+1);
                    j++;
                }
            }
            else{
                if(nums[j]==1){
                    len=max(len,j-i+1);
                    j++;
                }
                else{
                    if(nums[i]==0){
                        i++;
                        count0--;
                    }
                    else i++;
                }
            }

        }
        return len;
    }
};