#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        int people[n];
        for (int i = 0; i < n; i++)
        {
            cin >> people[i];
        }
        sort(people, people + n);
        for (int i = 0; i < n; i++)
        {
            if (people[i] <= cnt)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}