class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sum=0;
        int prev_one=0;
        for(int i=0;i<bank.size();i++){
             int current_one=0;
             for(int j=0;j<bank[i].length();j++){
                 if(bank[i][j]=='1')current_one++;
             }
             
             if(current_one!=0){
                 sum+=prev_one*current_one;
                 prev_one=current_one;
                 
             }
        }
        return sum;
    }
};