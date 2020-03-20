#include <bits/stdc++.h>
using namespace std;

bool myCompare(string a, string b)
{
    string s1 = a.append(b);
    string s2 = b.append(a);

    // int x = stoi(s1);
    // int y = stoi(s2);

    // return x > y;

    return s1 > s2;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end(), myCompare);

        for (int i = 0; i < n; i++)
        {
            cout << v[i];
        }

        cout << endl;
    }

    return 0;
}