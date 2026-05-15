class Solution {
public:
    int findMin(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        int curr_min = 1e9;
        while(i <= j){
            int m = i + (j - i) / 2;
            if(arr[i] <= arr[m]){
                curr_min = min(curr_min, arr[i]);
                i = m + 1;
            }
            else {
                curr_min = min(curr_min, arr[m]);
                j = m - 1;
            }
            
        }
        return curr_min;
    }
};