// In the name of Allah the most gracious, most merciful.
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void action()
{
    int n;  cin>>n;
    int  a[n], sum = 0, i;
    bool even = false, odd = false;
    for (i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]%2==0)
            even = true;
        else
            odd = true;
    }
    if (even==true && odd==true)
        cout<<"No"<<endl;
    else if (sum%n==0)
    {
        if (even==true)
        {
            if ((sum/n)%2==0)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else
        {
            if ((sum/n)%2!=0)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
}
/* -- Main Function -- */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        action();
    }
    return 0;
}