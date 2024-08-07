#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        int p = n + m + 1;
        vector <int> prog(p);
        vector <int> test(p);

        for(int i = 0; i < p; i ++){
            cin >> prog[i];
        }

        for(int i = 0; i < p; i ++){
            cin >> test[i];
        }

        int l = n;
        int r = m;

        int a = -1;
        int b = -1;

        vector <long long> ans;

        vector <long long> prefix(p + 1);
        int check = -1;
        int which = -1;

        for(int i = 0; i < p ; i ++){
            if(l > 0 and r > 0){
                if(prog[i] > test[i]){
                    prefix[i+1] = prog[i] + prefix[i];
                    l --;
                }
                else{
                    prefix[i+1] = test[i] + prefix[i];
                    r --;
                }
            }
            else{

                if(prog[i] > test[i] and a == -1){
                    a = i;
                }

                if(prog[i] < test[i] and b == -1){
                    b = i;
                }

                if(l > 0){
                    if(check == -1) check = i-1, which = 0;
                    prefix[i+1] = prog[i] + prefix[i];
                }
                else{
                    if(check == -1) check = i-1, which = 1;
                    prefix[i+1] = test[i] + prefix[i];
                }
            }

        }

        if(a == -1){
            a = p-1;
        }

        if(b == -1){
            b = p-1;
        }

        //cout << "hello" << a << ' ' << b << " " << check << ' ' << which << endl;

        long long sum = 0;
        for(int i = p-1; i >= 0; i --){
            if(i > check){
                if(which == 0){
                    ans.push_back(prefix[i+1] + sum - prog[i]);
                    sum += prog[i];
                }
                else{
                    ans.push_back(prefix[i+1] + sum - test[i]);
                    sum += test[i];
                }
            }
            else{
                if(prog[i] > test[i]){
                    ans.push_back(prefix[i+1] + sum - prog[i] + prog[a] - (which == 0 ? prog[a] : test[a]));
                    sum += prog[i];
                }
                else{
                    ans.push_back(prefix[i+1] + sum - test[i] + test[b] - (which == 0 ? prog[b] : test[b]));
                    sum += test[i];
                }
            }
        }

        reverse(ans.begin(), ans.end());

        for(auto a: ans){
            cout << a << " ";
        }
        cout << endl;
    }
}