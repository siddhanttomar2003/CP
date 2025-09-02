class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
            if(a[0] != b[0])return a[0] < b[0];
            return a[1] > b[1];
        });
        for(int i = 0; i < points.size(); i++){
            cout << points[i][0] << " " << points[i][1] << endl;
        }
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            int maxi = points[i][1];
            int mini = -1e9;
            for(int j = i + 1; j < points.size(); j++){
                if(points[j][1] <= maxi){
                    if(points[j][1] > mini){
                        mini = max(mini, points[j][1]);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};