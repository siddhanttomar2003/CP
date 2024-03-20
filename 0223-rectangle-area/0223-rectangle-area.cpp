class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // we just need to remove the common area from the summation of both areas
        //->For common area
      int new_left=max(ax1,bx1);
      int new_right=min(ax2,bx2);
      int new_bottom=max(ay1,by1);
      int new_top=min(ay2,by2);
      int common_area=0;

      if(new_left<new_right&&new_top>new_bottom){
        common_area=(new_right-new_left)*(new_top-new_bottom);
      }
      return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-common_area;



    }
};