#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int n, int open, int close, string s)
{
    //Base case
    if (close == n)
    {
        cout << s << endl;

        return;
    }

    //Rec case
    if (close < open)
    {
        // I can place another close bracket in my expression
        generateParenthesis(n, open, close + 1, s + ")");
    }
    if (open < n)
    {
        // I can place another opening bracket in my expression
        generateParenthesis(n, open + 1, close, s + "(");
    }
}

int main()
{
    int n;
    cin >> n;

    generateParenthesis(n, 0, 0, "");

    return 0;
}