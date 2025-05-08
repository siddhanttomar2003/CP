class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left_max,right_max;
        left_max=height[0];right_max=height[n-1];
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            if(height[l]<=height[r]){
                 int curr=(left_max-height[l]);
                 if(curr>0)ans+=curr;
                 left_max=max(left_max,height[l]);
                 l++;
            }
            else {
                 int curr=(right_max-height[r]);
                 if(curr>0)ans+=curr;
                 right_max=max(right_max,height[r]);
                 r--;
            }
        }
        return ans;
    }
};