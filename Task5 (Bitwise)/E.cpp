#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        if (a == b)
        {
            cout << 0 << '\n';
            continue;
        }

        // Impossible
        if ((a | b) != a)
        {
            cout << -1 << '\n';
            continue;
        }

        vector<long long> ops;

        // Remove extra bits from a
        for (int bit = 60; bit >= 0; bit--)
        {
            if (((a >> bit) & 1) && !((b >> bit) & 1))
            {
                long long x = (1LL << bit);
                ops.push_back(x);
                a ^= x;
            }
        }

        // Final safety check
        if (a != b || ops.size() > 100)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << ops.size() << '\n';
            for (long long x : ops)
                cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}