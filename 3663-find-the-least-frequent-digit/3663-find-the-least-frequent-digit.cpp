class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int>temp(10, 0);
        while(n){
            temp[n % 10]++;
            n /= 10;
        }
        int mini = 1e9;
        for(int i = 0; i < 10; i++){
            if(temp[i] > 0)mini = min(mini, temp[i]);
        }
        for(int i = 0; i < 10; i++){
            if(temp[i] == mini)return i;
        }
        return -1;
    }
};