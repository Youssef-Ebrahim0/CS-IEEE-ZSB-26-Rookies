#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long BS_prod(long long start, long long end, const vector<long long> &k, long long n, long long t)
{
    long long mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        long long total = 0;
        for (int i = 0; i < n; ++i)
        {
            total += mid / k[i];
        }

        if (total >= t)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    // input
    int n;
    long long t;
    cin >> n >> t;
    vector<long long> k(n);
    for (int i = 0; i < n; ++i)
        cin >> k[i];

    // process
    sort(k.begin(), k.end());
    int min = k[0];

    long long start = 1, end = t * min;

    cout << BS_prod(start, end, k, n, t) << endl;
    return 0;
}