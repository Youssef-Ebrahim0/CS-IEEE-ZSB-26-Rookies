#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


bool suit_R(long long r, const vector<long long> &cities, const vector<long long> &towers)
{
    for (long long city : cities)
    {
        auto it = lower_bound(towers.begin(), towers.end(), city);
        long long closest = LLONG_MAX;

        if (it != towers.end())
            closest = min(closest, abs(*it - city));
        if (it != towers.begin())
        {
            it--;
            closest = min(closest, abs(*it - city));
        }

        if (closest > r)
            return false;
    }
    return true;
}

long long BS_R(long long start, long long end, const vector<long long> &cities, const vector<long long> &towers)
{
    long long mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (suit_R(mid, cities, towers))
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
    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Maximum possible radius is distance between furthest points
    long long max_coord = max(abs(a.front() - b.front()), abs(a.back() - b.back()));

    cout << BS_R(0, max_coord+1, a, b) << endl;

    return 0;
}
