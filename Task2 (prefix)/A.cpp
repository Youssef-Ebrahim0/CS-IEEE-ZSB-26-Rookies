#include <iostream>
#include <vector>
using namespace std;

// int sum_range(const vector<int> &arr, int start, int end)
// {
//     return arr[end] - arr[start - 1];
// }

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    vector<long long> prefix_sum(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 1-based
    for (int i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[b] - prefix_sum[a - 1] << endl;
    }

    return 0;
}
