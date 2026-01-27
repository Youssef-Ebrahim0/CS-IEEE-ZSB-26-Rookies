#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int i = 0; i < n; i++)
            cin >> w[i];

        int l = 0, r = n - 1;
        long long sum_left = 0, sum_right = 0;
        int ans = 0;

        while (l <= r)
        {
            if (sum_left < sum_right)
                sum_left += w[l++];
            else
                sum_right += w[r--];

            if (sum_left == sum_right)
                ans = max(ans, l + (n - r - 1));
        }

        cout << ans << '\n';
    }
    return 0;
}
