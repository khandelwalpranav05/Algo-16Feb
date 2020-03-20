#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &ans, int x)
{
    int carry = 0;

    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] *= x;
        ans[i] += carry;

        carry = ans[i] / 10;
        ans[i] %= 10;
    }

    while (carry > 0)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }
}

int main()
{
    int n;
    cin >> n;

    // int f = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     f *= i;
    // }

    // cout << f;

    vector<int> ans(1, 1);

    for (int i = 1; i <= n; i++)
    {
        multiply(ans, i);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[ans.size() - i - 1];
    }

    return 0;
}