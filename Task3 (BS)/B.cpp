#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BS(vector<int> &x, long long m)
{
    int start = 0, end = x.size() - 1;
    int ans = -1;//last valid index
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (x[mid] <= m)
        {
            ans = mid;          
            start = mid + 1;//try larger 
        }
        else
        {
            end = mid - 1;//too large
        }
    }
    return ans + 1;
}

int main()
{
    // read input
    int n;
    cin >> n;
    vector<int> x(n);//prices
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int q;
    cin >> q;
    vector<int> m(q);//coins
    for (int i = 0; i < q; i++)
    {
        cin >> m[i];
    }

    // process
    sort(x.begin(), x.end());
    for (int i = 0; i < q; i++)
    {
        cout << BS(x, m[i]) << "\n";
    }
}