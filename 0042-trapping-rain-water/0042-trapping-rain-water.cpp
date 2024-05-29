class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxLeft=0;
        int maxRight=0;
        int ans=0;
        while(l<=r){
           if(height[l]<=height[r]){
            if(height[l]>=maxLeft){
                maxLeft=height[l];
            }
            else {
                ans+=(maxLeft-height[l]);
            }
            l++;
           }
           else {
            if(height[r]>=maxRight){
                maxRight=height[r];
            }
            else {
                ans+=(maxRight-height[r]);
            }
              r--;
           }
         
        }
        return ans;
    }
};