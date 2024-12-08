class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         vector<int>freq(1001,0);
         for(int i=0;i<trips.size();i++){
            int start=trips[i][1];
            int end=trips[i][2];
            int passengers=trips[i][0];
            freq[start]+=passengers;
            freq[end]-=passengers;
         }
         for(int i=1;i<1001;i++){
            freq[i]+=freq[i-1];
            if(freq[i]>capacity)return false;
         }
         if(freq[0]>capacity)return false;
         return true;
    }
};