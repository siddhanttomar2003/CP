class Solution {
public:
    bool check(int m, vector<pair<double,int>>&temp, int size, vector<int>&cost, vector<int>&time){
        int sum = 0;
        int count = 0;
        for(int i = 0; i < temp.size(); i++){
              int ind = temp[i].second;
              if(cost[ind] <= m){
                 sum += time[ind];
                 m -= cost[ind];
                 count ++;
              }
        }
        return sum + count >= size;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<pair<double,int>>temp;
        for(int i = 0; i < cost.size(); i++){
            temp.push_back( { (cost[i] * 1.0) / (time[i] * 1.0), i } );
        }
        sort(temp.begin(), temp.end());
        int low = 0;
        int high = accumulate(cost.begin(), cost.end(), 0);
        int ans = high;
        int size = cost.size();
        while(low <= high){
            int m = low + (high - low) / 2;
            if(check(m, temp, size, cost, time)){
                ans = m ;
                high = m - 1;
            }
            else low = m + 1;
        }
        return ans;
    }
};