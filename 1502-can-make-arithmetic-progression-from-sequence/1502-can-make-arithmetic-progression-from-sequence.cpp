class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n == 2)return true;
        for(int i = 0; i < n - 2; i++){
            if(arr[i] - arr[i + 1] != arr[i + 1] - arr[i + 2])return false;
        }
        return true;
    }
};