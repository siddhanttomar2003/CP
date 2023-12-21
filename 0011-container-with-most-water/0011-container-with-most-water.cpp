class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int max_area=0;
        while(s<e){
         int area=(e-s)*min(height[s],height[e]);
         if(area>max_area)max_area=area;
         int a=height[s];int b=height[e];
         if(a>b)e--;
         else s++;

        }
        return max_area;
    }
};