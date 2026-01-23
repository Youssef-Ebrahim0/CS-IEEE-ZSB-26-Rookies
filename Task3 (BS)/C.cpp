#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can(int k, const vector<int> &H, const vector<int> &B, int n, int m)
{
    int i = 0, j = 0, count = 0;
    while (i < n && j < m && count < k)
    {
        if (H[i] <= B[j])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count >= k;
}

int BS_maxrob(const vector<int> &H, const vector<int> &B, int n, int m)
{
    int start = 0, end = min(n, m);
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (can(mid, H, B, n, m))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    // input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> H(n);
    vector<int> B(m);
    for (int i = 0; i < n; ++i)
        cin >> H[i];
    for (int j = 0; j < m; ++j)
        cin >> B[j];

    // process
    sort(H.begin(), H.end());
    sort(B.begin(), B.end());

    int maxRobots = BS_maxrob(H, B, n, m);
    cout << (maxRobots >= k ? "Yes" : "No") << '\n';
    return 0;
}