class Solution {
public:
    bool pos(int i, int j, vector<vector<int>>&f, int k, int s){
        cout << i << " " << j << endl;
        int right_dis = 0, left_dis = 0;
        if(s <= f[j][0] && s >= f[i][0]){
            int mini = min(s - f[i][0] , f[j][0] - s);
            int maxi = max(s - f[i][0] , f[j][0] - s);
            return 2 * mini + maxi <= k;
        }
        else if(s >= f[j][0]){
            return s - f[i][0] <= k;
        }
        else if(s <= f[i][0])
            return f[j][0] - s <= k;
        else cout << "What" << endl;
        return false;
        
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int ans = 0;
        int i = 0, j = 0;
        int maxi = 0;
        int sum = 0;
        while(j < n){
            sum += fruits[j][1];
            while(i <= j && !pos(i, j, fruits, k, startPos)){
                cout << sum << endl;
                sum -= fruits[i][1];
                i++;
            }
            maxi = max(maxi, sum);
            j++;
        }
        return maxi;
    }
};