class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(m < n){
            swap(nums1, nums2);
            swap(n, m);
        }
        int tot = n + m;
        
            int take = (n + m  + 1) / 2;
            int i = 0;
            int j = n;
            while(i <= j){
                int mid = (i + j) / 2;
                int take1 = mid;
                int take2 = take - mid;
                int l1 = -1e9;
                if(take1 > 0) l1 = nums1[take1 - 1];
                int l2 = -1e9;
                if(take2 > 0) l2 = nums2[take2 - 1];
                int r1 = 1e9;
                if(take1 < n) r1 = nums1[take1];
                int r2 = 1e9;
                if(take2 < m) r2 = nums2[take2];
                if(l1 > r2){
                    j = mid - 1;
                }
                else if(l2 > r1){
                    i = mid + 1;
                }
                else {
                    if(tot % 2 == 0)
                    return double(max(l1, l2) + min(r1 , r2)) / (2 * 1.00);
                    else return max(l1, l2);
                }
            }
            return 1.00;
        
        
    }
};