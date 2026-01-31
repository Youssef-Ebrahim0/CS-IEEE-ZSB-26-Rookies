#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<long long> prefixXor(n + 1, 0); // answer= pref[b] xor pref[a−1]
    for (int i = 1; i <= n; i++)
    {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1];
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (prefixXor[b] ^ prefixXor[a - 1]) << '\n';
    }
    return 0;
}