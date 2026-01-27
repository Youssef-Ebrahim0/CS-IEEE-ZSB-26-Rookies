#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    // proc
    int l = 0, r = n - 1;
    int sum_left = 0, sum_right = 0;
    int a=0, b=0;
    while (l <= r)
    {
        if (sum_left + t[l] <= sum_right + t[r])
        {
            sum_left += t[l];
            l++;
            a++;
        }
        else
        {
            sum_right += t[r];
            r--;
            b++;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}