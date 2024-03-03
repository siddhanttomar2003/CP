class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a=0;int b=0;int c=0;int d=0;
        string first = "";
        string second = "";
        bool flag = false;
        for (int i = 0; i < num1.size(); i++) {
            if (!flag) {
                first += num1[i];
            }
            if (num1[i] == '+') {
                flag = true;
                continue;
            }
            if (flag) {
                if (num1[i] != 'i')
                    second += num1[i];
            }
        }
        string third = "";
        string fourth = "";
        bool flagi = false;
        for (int i = 0; i < num2.size(); i++) {
            if (!flagi) {
                third += num2[i];
            }
            if (num2[i] == '+') {
                flagi = true;
                continue;
            }
            if (flagi) {
                if (num2[i] != 'i')
                    fourth += num2[i];
            }
        }
        a = stoi(first);
        b = stoi(second);
        c = stoi(third);
        d = stoi(fourth);
        int op1 = a * c - b * d;
        int op2 = a * d + b * c;
        string ans=to_string(op1)+'+'+to_string(op2)+'i';
        return ans;
    }
};