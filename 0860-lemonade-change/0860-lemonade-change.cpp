class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        long long rem5=0;
        long long rem10=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5)rem5++;
            else if(bills[i]==10){
                if(rem5>0){
                    rem5--;
                    rem10++;
                }
                else return false;
            }
            else {
                if(rem10>=1 && rem5>=1){
                     rem10--;rem5--;
                }
                else if(rem5>=3)rem5-=3;
                else return false;
            }
        }
        return true;
    }
};