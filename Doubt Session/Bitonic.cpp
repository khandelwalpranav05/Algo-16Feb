#include <bits/stdc++.h>
using namespace std;

int maxBitonicSubarray(vector<int> v)
{
    int n = v.size();

    vector<int> inc(n, 1);
    vector<int> dec(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (v[i] >= v[i - 1])
        {
            inc[i] = inc[i - 1] + 1;
        }
        else
        {
            inc[i] = 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] >= v[i + 1])
        {
            dec[i] = dec[i + 1] + 1;
        }
        else
        {
            dec[i] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, inc[i] + dec[i] - 1);
    }

    return ans;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        cout << maxBitonicSubarray(v) << endl;
    }

    return 0;
}