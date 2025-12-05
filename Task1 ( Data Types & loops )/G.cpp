#include <iostream>
using namespace std;

int main()
{
    int k, r;
    cin >> k >> r;

    for (int i = 1; i <= 10; i++)//max digits 0-9
    {
        int last_dig = k % 10;
        if ((last_dig * i) % 10 == 0 || (last_dig * i) % 10 == r)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}