#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const long long MOD = 1e9 + 7;
    long long n;
    cin >> n;

    long long result = 1;
    long long base = 2;// 2^n

    while (n > 0)
    {
        if (n % 2 == 1)
            result = (result * base) % MOD;

        base = (base * base) % MOD;
        n /= 2;//shift right
    }

    cout << result << '\n';
    return 0;
}
