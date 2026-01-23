#include <iostream>
using namespace std;

int BS_ff(int start, int end, int n, int k)
{
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        long long sum = 0;
        long long cur = mid;

        while (cur > 0)
        {
            sum += cur;
            cur /= k;
        }

        if (sum >= n)
        {
            end = mid - 1; //try smaller
        }
        else
        {
            start = mid + 1; //too small
        }
    }
    return start; //minimum v
}

int main()
{
    long long n; // total lines
    int k;   // productivity reduction
    cin >> n >> k;

    long long start = 1, end = n;
    cout << BS_ff(start, end, n, k) << endl;
    return 0;
}
