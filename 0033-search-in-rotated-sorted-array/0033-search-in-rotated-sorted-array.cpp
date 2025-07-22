class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            // check left half sorted
            if(target == arr[mid])return mid;
            if(arr[mid] >= arr[0]){
                if(target >= arr[0] && target <= arr[mid]){
                        j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            else {
                if(target >= arr[mid] && target <= arr[j]){
                    i = mid + 1;
                }
                else j = mid - 1;
            }
        }
        return -1;
    }
};