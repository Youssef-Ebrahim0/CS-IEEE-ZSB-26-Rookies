#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> costs(n);
    vector<long long> prefix_sum(n + 1, 0);
    vector<long long> sorted_costs;

    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
        prefix_sum[i + 1] = prefix_sum[i] + costs[i];
    }

    sorted_costs = costs;
    sort(sorted_costs.begin(), sorted_costs.end());
    vector<long long> sorted_prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        sorted_prefix_sum[i] = sorted_prefix_sum[i - 1] + sorted_costs[i - 1];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int type, start, end;
        cin >> type >> start >> end;

        if (type == 1)
        {
            cout << prefix_sum[end] - prefix_sum[start - 1] << endl;
        }
        else if (type == 2)
        {
            cout << sorted_prefix_sum[end] - sorted_prefix_sum[start - 1] << endl;
        }
    }
}