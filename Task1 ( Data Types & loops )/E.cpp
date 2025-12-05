#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string cond = "codeforces";

    while (t--)
    {
        char c;
        cin >> c;
        bool found = false;

        for (int i = 0; i < cond.length(); i++)
        {
            if (c == cond[i])
            {
                found = true;
                break; // stop
            }
        }// or using cond.find(c) 

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
