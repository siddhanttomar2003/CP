#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        long long a,b;
        cin>>a>>b;
        while(a!=b){
            if(b>a){
                b/=(2*1ll);
            }
            else a/=(2*1ll);
        }
        cout<<a<<endl;
    }
}