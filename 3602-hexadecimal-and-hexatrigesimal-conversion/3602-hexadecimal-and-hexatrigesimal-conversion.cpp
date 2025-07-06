class Solution {
public:
    string concatHex36(int n) {
        int num1= n * n;
        int num2 = n * n * n;
        string f = "", s = "";
        map<int,char>mp1,mp2;
        for(int i = 0; i <= 15;i++){
           if(i <= 9){
            mp1[i] = i + 48;
           }
           else mp1[i] = 'A' + (i - 10);
        }
        for(int i = 0; i <= 35; i++){
            if(i <= 9)mp2[i] = i + 48;
            else mp2[i] = 'A' + (i - 10);
        }
        // cout << num1 << endl;
        for(auto it : mp1)cout << it.first << " " << it.second << endl;
        while(num1 > 0){
            int rem = num1 % 16;
            f += mp1[rem];
            num1 /= 16;
        }
        reverse(f.begin(), f.end());
        while(num2 > 0){
            int rem = num2 % 36;
            s += mp2[rem];
            num2 /= 36;
        }
        reverse(s.begin(), s.end());
        return f + s;
    }
};