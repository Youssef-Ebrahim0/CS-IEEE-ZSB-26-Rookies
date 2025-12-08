#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<long long, int> mp; // value -> index

    for (int i = 0; i < n; i++)
    {
        long long need = x - arr[i];
        if (mp.count(need))
        {
            cout << mp[need] + 1 << " " << i + 1 << endl;
            return 0;
        }
        mp[arr[i]] = i; //index
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}

// o(n^2) error
// int main()
// {
//     long int n, sum;
//     cin >> n >> sum;

//     vector<long long int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i + 1; j < arr.size(); j++)
//         {
//             if (arr[i] + arr[j] == sum)
//             {
//                 cout << i + 1 << " " << j + 1 << endl;
//                 return 0;
//             }
//         }
//     } // else
//     cout << "Impossible" << endl;
// }