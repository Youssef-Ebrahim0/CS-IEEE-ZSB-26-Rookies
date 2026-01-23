#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long int n;
    cin >> n;

    // if summision = even -> possible  || else immpossible
    long int summ = n * (n + 1) / 2;
    long int target = summ / 2;
    vector<int> group1, group2;

    if (summ % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = n; i >= 1; i--)
        {
            if (target - i >= 0)
            {
                group1.push_back(i);
                target -= i;
            }
            else
            {
                group2.push_back(i);
            }
        }
        cout << group1.size() << endl;
        for (auto num : group1)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << group2.size() << endl;
        for (auto num : group2)
        {
            cout << num << " ";
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}