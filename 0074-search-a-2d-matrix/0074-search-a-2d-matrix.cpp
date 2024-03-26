class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
         int start=0;
         int end=r-1;
         int pos_row=-1;
         while(start<=end){
           int mid=start+(end-start)/2;
           if(matrix[mid][c-1]>=target){
            pos_row=mid;
            end=mid-1;
           }
           else{
            start=mid+1;
           }
         }
         if(pos_row==-1)return false;
         int s=0;
         int e=c-1;
         while(s<=e){
            int m=s+(e-s)/2;
            if(matrix[pos_row][m]==target)return true;
            else if(matrix[pos_row][m]<target)s=m+1;
            else e=m-1;
         }
         return false;

    }
};