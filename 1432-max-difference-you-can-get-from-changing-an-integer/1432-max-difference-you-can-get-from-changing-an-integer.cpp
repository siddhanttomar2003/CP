class Solution {
public:
    int maxDiff(int num) {
        string temp = to_string(num);
        int n = temp.size();
        int a = 0;
        for (int i = 0; i < n; i++) {
            string curr = "";
            for (int j = 0; j < n; j++) {
                if (temp[i] == temp[j]) {
                    curr += '9';
                } else
                    curr += temp[j];
            }
            int ele = stoi(curr);
            a = max(a, ele);
        }
        int b = 1e9;

        for (int i = 0; i < n; i++) {
            string curr1 = "", curr2 = "";
            for (int j = 0; j < n; j++) {
                if (temp[i] == temp[j]) {
                    curr1 += '0';
                    curr2 += '1';
                } else {
                    curr1 += temp[j];
                    curr2 += temp[j];
                }
            }
            int num1=stoi(curr1);
            int num2=stoi(curr2);
            curr1=to_string(num1);
            curr2=to_string(num2);
            if(curr1.size()==temp.size() && num1!=0)b=min(b,num1);
            if(curr2.size()==temp.size())b=min(b,num2);
        }
        return a-b;

    }
};