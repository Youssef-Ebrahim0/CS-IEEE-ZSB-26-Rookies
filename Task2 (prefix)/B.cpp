#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<long long> arr(n + 1);
        vector<long long> prefix_sum(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        }
        long long total_sum = prefix_sum[n]; // total old sum

        for (int i = 1; i <= q; i++)
        {
            int start, end;
            long long value;
            cin >> start >> end >> value;
            // new = old - old_range + new_range
            long long new_sum = total_sum - (prefix_sum[end] - prefix_sum[start - 1]) + (value * (end - start + 1));

            if (new_sum % 2 == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}// TLE -_-
// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, q;
//         cin >> n >> q;

//         vector<long long> arr(n + 1);

//         for (int i = 1; i <= n; i++)
//         {
//             cin >> arr[i];
//         }

//         vector<long long> original = arr;
//         for (int i = 1; i <= q; i++)
//         {
//             int start, end;
//             long long value;
//             cin >> start >> end >> value;

//             //! replace with new value
//             for (int j = start; j <= end; j++)
//             {
//                 arr[j] = value;
//             }

//             //! calc new sum
//             long long sum = 0;
//             for (int z = 1; z <= n; z++)
//             {
//                 sum += arr[z];
//             }

//             if (sum % 2 == 1)
//             {
//                 cout << "YES" << endl;
//             }
//             else
//             {
//                 cout << "NO" << endl;
//             }
//             arr = original;
//         }
//     }
// }