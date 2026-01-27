#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first; // value
        a[i].second = i;   // original index
    }

    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    while (l < r)
    {
        long long sum = a[l].first + a[r].first;
        if (sum == x)
        {
            cout << a[l].second + 1 << " " << a[r].second + 1 << endl;
            return 0;
        }
        else if (sum < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
