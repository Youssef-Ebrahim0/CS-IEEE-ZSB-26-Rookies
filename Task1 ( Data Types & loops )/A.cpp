#include <iostream>
using namespace std;

int main()
{
    int n; // contest num
    int count = 0;
    cin >> n;
    // check range
    if (n < 1 || n > 1000)
    {
        printf("n out of range\n");
        return -1;
    }

    for (int i = 1; i <= n; i++)
    {
        int f1, f2, f3;// 3 friends
        cin >> f1 >> f2 >> f3;
        if (f1 + f2 + f3 >= 2)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}