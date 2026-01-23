#include <iostream>
#include <vector>
using namespace std;

//Euclidean GCD
long long GCD(long long a, long long b)
{
    return b == 0 ? a : GCD(b, a % b);
}

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Prefix GCD: GCD from start to current index
    vector<long long> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = GCD(prefix[i - 1], arr[i]);

    // Suffix GCD: GCD from current index to end
    vector<long long> suffix(n);
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = GCD(suffix[i + 1], arr[i]);

    long long max_gcd = 0;

    for (int i = 0; i < n; i++)
    {
        long long current_gcd;
        if (i == 0)
            current_gcd = suffix[1]; // ignore first 
        else if (i == n - 1)
            current_gcd = prefix[n - 2]; // ignore last 
        else
            current_gcd = GCD(prefix[i - 1], suffix[i + 1]); // ignore middle 

        max_gcd = max(max_gcd, current_gcd);
    }

    cout << max_gcd << endl;
    return 0;
}

// long long GCD(long long a, long long b)
// {
//     if (b == 0)
//         return a;
//     return GCD(b, a % b);
// }

// long long GCD_vec(const vector<long long> &arr, int skip = 0)
// {
//     long long result = 0;
//     for (size_t i = 0; i < arr.size(); i++)
//     {
//         if (i == skip)
//             continue;
//         result = GCD(result, arr[i]);
//     }
//     return result;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<long long> arr(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     long long max_gcd = 0;

//     for (int i = 0; i < n; i++)
//     {
//         long long current_gcd = GCD_vec(arr, i);
//         max_gcd = max(max_gcd, current_gcd);
//     }
//     cout << max_gcd << endl;
//     return 0;
// }
