#include <bits/stdc++.h>
using namespace std;

long long int arr[1000];


long long int optimal(long long int i, long long int j)
{
    //Base case
    if (i > j)
    {
        return 0;
    }

    long long int pickFirst = arr[i] + min(optimal(i + 2, j), optimal(i + 1, j - 1));
    long long int pickLast = arr[j] + min(optimal(i, j - 2), optimal(i + 1, j - 1));

    long long int ans = max(pickFirst, pickLast);

    return ans;
}

int main()
{
    long long int n;
    cin >> n;

    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << optimal(0, n - 1);

    return 0;
}
