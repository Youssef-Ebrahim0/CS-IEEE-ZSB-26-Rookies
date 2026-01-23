#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int X, N, Q; // X: total weight, N: number of parts, Q: number of queries
    
    cin >> X;
    cin >> N;

    vector<int> parts_weight(N);
    vector<bool> appeared(N, false);

    for (int i = 0; i < N; i++)
    {
        cin >> parts_weight[i];
    } // W(i) -> W(N)

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int p; // p: query
        cin >> p;

        if (!appeared[p-1])
        {
            X = X + parts_weight[p - 1];
            appeared[p-1] = true;
        }
        else
        {
            X = X - parts_weight[p - 1];
            appeared[p-1] = false;
        }
        cout << X << endl;
    }
    return 0;
}