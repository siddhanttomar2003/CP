class Solution {
public:
    int rotatedDigits(int n) {
        // 0, 1, 8
        // 6, 9
        // 2, 5
        // not 3, 4, 7
        int count = 0;
        for(int i = 1; i <= n; i++){
            string curr = to_string(i);
            int idx = -1;
            bool check = false;
            for(int j = 0; j < curr.size(); j++){
                if(curr[j] == '3' || curr[j] == '4' || curr[j] == '7'){
                    idx = j;
                    break;
                }
                if(curr[j] == '6' || curr[j] == '9' || curr[j] == '2' || curr[j] == '5')check = true;
            }
            if(idx == -1){
                if(check)count++;
                continue;
            }
            else {
                curr[idx] = curr[idx] + '1' - 48;
                for(int j = idx + 1; j < curr.size(); j++){
                    curr[j] = '0';
                }
                cout << curr << endl;
                i = stoi(curr);
                i--;
            }
        }
        return count;
    }
};