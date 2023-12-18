class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest=0;
        int second_largest=0;
              int smallest=INT_MAX;
        int second_smallest=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=largest){
                second_largest=largest;
                largest=nums[i];
            }
            else if(nums[i]>second_largest&&nums[i]<largest){
                second_largest=nums[i];
            }
            if(nums[i]<=smallest){
                second_smallest=smallest;
                smallest=nums[i];
            }
            else if(nums[i]<second_smallest&&nums[i]>smallest){
                second_smallest=nums[i];
            }
        }
        int product_max=largest*second_largest;
        int product_min=smallest*second_smallest;
        return product_max-product_min;
        
  

    }
};