#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int Max = max(a, max(b, c));
        if (Max == (a + b + c - Max))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}