#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 2p process
    int max_num = 0;
    int current_sum = 0;
    int l = 0, r = 0;

    while (r < n)
    {
        current_sum += a[r];
        while (current_sum > t)
        {
            current_sum -= a[l];
            l++;
        }
        max_num = max(max_num, r - l + 1);// max length
        r++;
    }
    cout << max_num << endl;
    return 0;
}