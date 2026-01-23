#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string seq;
    cin >> seq;

    int max_len = 1;
    int rep = 1;//start from 1
    for (int i = 1; i <= seq.size() - 1; i++)
    {
        if (seq[i] == seq[i - 1])
        {
            rep++;
        }
        else
        {
            rep = 1;
        }
        if (rep > max_len)
        {
            max_len = rep;
        }
    }
    cout << max_len << endl;
    return 0;
}