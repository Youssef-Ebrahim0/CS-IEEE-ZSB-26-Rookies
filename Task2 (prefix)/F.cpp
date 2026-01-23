#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    // difference array
    vector<int> count(200001, 0);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        count[start]++;
        count[end + 1]--;
    }

    // prefix sum to get actual counts
    for (int i = 1; i <= 200000; i++)
    {
        count[i] += count[i - 1];
    }

    // admisible array
    vector<int> admisible(200000 + 1, 0);
    for (int i = 1; i <= 200000; i++)
    {
        if (count[i] >= k)
            admisible[i] = 1;
    }

    // prefix sum of admisible
    vector<int> prefix_sum(200000 + 1, 0);
    for (int i = 1; i <= 200000; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + admisible[i];
    }

    for (int i = 0; i < q; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << prefix_sum[end] - prefix_sum[start - 1] << endl;
    }
}