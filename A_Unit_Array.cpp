#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int neg=0;
        int pos=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(v[i]<0)neg++;
            else pos++;
        }
        if(neg%2){
            count++;
            neg--;pos++;
        }
        if(pos>=neg)cout<<count<<endl;
        else {
            int curr=neg-pos;
            int req=curr/2+curr%2;
            if(req&1)req++;
            cout<<count+req<<endl;

        }
    }

    return 0;
}