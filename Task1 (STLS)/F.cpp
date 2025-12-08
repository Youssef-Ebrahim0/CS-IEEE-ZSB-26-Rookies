#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> res(n);
    stack<int> s; // indices

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop(); // pop until find smaller element
        }
        if (s.empty())
        {
            res[i] = 0; // no smaller element
        }
        else
        {
            res[i] = s.top() + 1;
        }
        s.push(i);
    }

    for (auto num : res)
    {
        cout << num << " ";
    }
    return 0;
}

// Time limit exceeded
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     vector<int> res;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     for (int i = 0; i < n ; i++)
//     {
//         int pos = 0;
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (arr[i] > arr[j])
//             {
//                 pos = j + 1;
//                 break;
//             }
//         }
//         res.push_back(pos);
//     }
//     for (auto num : res)
//     {
//         cout << num << " ";
//     }
//     return 0;
// }