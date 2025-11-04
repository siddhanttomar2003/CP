class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        for(int i = 0; i < colors.size(); i++){
            int sum = neededTime[i];
            int maxi = sum;
            while(i + 1 < colors.size() && colors[i] == colors[i + 1]){
                sum += neededTime[i + 1];
                maxi = max(maxi, neededTime[i + 1]);
                i++;
            }
            ans += (sum - maxi);
        }
        return ans;
    }
};