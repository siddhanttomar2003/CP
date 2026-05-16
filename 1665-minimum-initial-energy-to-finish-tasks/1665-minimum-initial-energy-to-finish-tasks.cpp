class Solution {
public:
    vector<vector<int>>arr;
    bool check(int m){
        int curr = m;
        for(auto &it : arr){
            if(curr >= it[1]){
                curr -= it[0];
            }
            else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b){
            return a[1] - a[0] > b[1] - b[0];
        });
        for(auto it : tasks)cout << it[0] << " " << it[1] << ",";
        arr = tasks;
        int i = 1, j = 2e9;
        int ans = 2e9;
        while(i <= j){
            int m = i + (j - i) / 2;
            if(check(m)){
                ans = m;
                j = m - 1;
            }
            else i = m + 1;
        }
        return ans;
    }
};