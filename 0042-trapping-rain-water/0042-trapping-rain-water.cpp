class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;int ans=0;
        int r=height.size()-1;int left_max=0;int right_max=0;
        while(l<r){
         if(height[l]<=height[r]){// in this its only possible that whether the water will be stored by height[l] block or not , it further depends on left_max as in according to right it can store the water 
          if(height[l]<left_max){
            ans+=(left_max-height[l]);
          }
          else {
            left_max=height[l];
          }
          l++;

         }
         else {
            if(height[r]<right_max){
                ans+=(right_max-height[r]);
            }
            else {
                right_max=height[r];
            }
            r--;
         }
        }
        return ans;
    }
};