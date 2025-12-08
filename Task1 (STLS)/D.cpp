#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s; // sets do not allow duplicates
    while (n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}