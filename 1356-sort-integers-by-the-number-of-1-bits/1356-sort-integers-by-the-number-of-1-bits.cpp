class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
            int count1 = 0, count2 = 0;
            for(int i = 0; i < 32; i++){
                if(a & (1 << i))count1++;
                if(b & (1 << i))count2++;
            }
            if(count1 != count2)return count1 < count2;
            return a < b;
        });
        return arr;
    }
};