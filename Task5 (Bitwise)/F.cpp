#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long all = 0; // ALL = a1 xor a2 xor ... xor aN
    for (int i = 0; i < n; i++)
    {
        all ^= a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << (all ^ a[i]) << endl; // xi = ALL xor a[i]
    }
    return 0;
}