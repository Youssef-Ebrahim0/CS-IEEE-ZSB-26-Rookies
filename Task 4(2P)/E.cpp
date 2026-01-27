#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

        // Two-pointer technique
    int l = 0;
    long long current_sum = 0;
    long long ans = 0;

    for (int r = 0; r < n; r++)
    {
        current_sum += a[r];

        while (current_sum > x)
        {
            current_sum -= a[l];
            l++;
        }

        if (current_sum == x)
            ans++;
    }

    cout << ans << "\n";
    return 0;
}