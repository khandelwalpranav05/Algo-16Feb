#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        // No disks
        return;
    }

    // Move N-1 disks from src to helper
    hanoi(n - 1, src, helper, dest);

    // Move Nth disk from src to dest - self work
    cout << "Moving ring " << n << " from " << src << " to " << dest << endl;

    // Move N-1 disks from helper to dest
    hanoi(n - 1, helper, dest, src);
}

int main()
{
    int n;
    cin >> n;

    hanoi(n, 'A', 'B', 'C');

    return 0;
}