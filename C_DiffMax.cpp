#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        map<long long, long long> mp_min;
        map<long long, long long> mp_max;
        for (int i = 0; i < n; i++)
        {
            if (mp_min.find(arr[i] % x) == mp_min.end())
            {
                mp_min[arr[i] % x] = arr[i];
            }
            else
                mp_min[arr[i] % x] = min(mp_min[arr[i] % x], arr[i]);
            if (mp_max.find(arr[i] % x) == mp_max.end())
            {
                mp_max[arr[i] % x] = arr[i];
            }
            else
                mp_max[arr[i] % x] = max(mp_max[arr[i] % x], arr[i]);
        }
        long long ans = 0;
       
        for (auto it : mp_min)
        {
                ans = max(ans, abs(it.second - mp_max[it.first]));
        }
        cout << ans << endl;
    }
}