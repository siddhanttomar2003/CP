#include <iostream>
#include <vector>
using namespace std;

const int m = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> curr(x + 1, 0), last(x + 1, 0);
    
    if (c[0] == 0)
    {
        for (int i = 1; i <= x; i++)
            last[i] = 1;
    }
    else
    {
        last[c[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        fill(curr.begin(), curr.end(), 0); 
        if (c[i] != 0)
        {
            int val = last[c[i]];
            if (c[i] > 1) val = (val + last[c[i] - 1]) % m;
            if (c[i] < x) val = (val + last[c[i] + 1]) % m;
            curr[c[i]] = val;
        }
        else
        {
            for (int j = 1; j <= x; j++)
            {
                int val = last[j];
                if (j > 1) val = (val + last[j - 1]) % m;
                if (j < x) val = (val + last[j + 1]) % m;
                curr[j] = val;
            }
        }
        last = curr;
    }

    int ans = 0;
    if (c[n - 1] == 0)
    {
        for (int i = 1; i <= x; i++)
        {
            ans = (ans + last[i]) % m;
        }
    }
    else
    {
        ans = last[c[n - 1]];
    }

    cout << ans << endl;
    return 0;
}
