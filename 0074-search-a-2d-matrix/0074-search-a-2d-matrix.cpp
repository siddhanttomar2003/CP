class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int tar=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;int high=n-1; 
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][m-1]>=target){
                tar=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        int low2=0;int high2=m-1;
        while(low2<=high2){
            int mid=low2+(high2-low2)/2;
            if(matrix[tar][mid]==target)return true;
            else if(matrix[tar][mid]<target)low2=mid+1;
            else high2=mid-1;
        }
        return false;


    }
};