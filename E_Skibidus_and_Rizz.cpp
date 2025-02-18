#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        if(m>=n){
            if(m<k||m-n>k){
                cout<<-1<<endl;
                continue;
            }
            string s="";
            for(int i=0;i<k;i++){
                s+='1';
            }
            m-=k;
            while(n>0||m>0){
                if(n>0){
                    s+='0';
                    n--;
                }
                if(m>0){
                    s+='1';
                    m--;
                }
            }
            cout<<s<<endl;
        }else{
            if(n<k||n-m>k){
                cout<<-1<<endl;
                continue;
            }
            string s="";
            for(int i=0;i<k;i++){
                s+='0';
            }
            n-=k;
            while(n>0||m>0){
                if(m>0){
                    s+='1';
                    m--;
                }
                if(n>0){
                    s+='0';
                    n--;
                }
            }
            cout<<s<<endl;
        }
    }
    return 0;
}