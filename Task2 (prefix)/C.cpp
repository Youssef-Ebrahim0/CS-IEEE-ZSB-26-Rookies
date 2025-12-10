#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("bcount.in");   
    ofstream fout("bcount.out"); 

    int n, q;
    fin >> n >> q;

    vector<int> breed(n + 1);
    vector<int> pref_1(n + 1, 0), pref_2(n + 1, 0), pref_3(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        fin >> breed[i];
        pref_1[i] = pref_1[i - 1] + (breed[i] == 1 ? 1 : 0);
        pref_2[i] = pref_2[i - 1] + (breed[i] == 2 ? 1 : 0);
        pref_3[i] = pref_3[i - 1] + (breed[i] == 3 ? 1 : 0);
    }

    for (int i = 0; i < q; i++)
    {
        int start, end;
        fin >> start >> end;

        int count_1 = pref_1[end] - pref_1[start - 1];
        int count_2 = pref_2[end] - pref_2[start - 1];
        int count_3 = pref_3[end] - pref_3[start - 1];

        fout << count_1 << " " << count_2 << " " << count_3 << "\n";
    }

    return 0;
}
//! ==============================================
// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<long long> breed(n + 1);
//     vector<long long> pref_1(n + 1, 0), pref_2(n + 1, 0), pref_3(n + 1, 0);

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> breed[i];
//         // easeir than if else
//         pref_1[i] = pref_1[i - 1] + (breed[i] == 1 ? 1 : 0);
//         pref_2[i] = pref_2[i - 1] + (breed[i] == 2 ? 1 : 0);
//         pref_3[i] = pref_3[i - 1] + (breed[i] == 3 ? 1 : 0);
//     }

//     for (int i = 0; i < q; i++)
//     {
//         int start, end;
//         cin >> start >> end;

//         int count_1 = pref_1[end] - pref_1[start - 1];
//         int count_2 = pref_2[end] - pref_2[start - 1];
//         int count_3 = pref_3[end] - pref_3[start - 1];

//         cout << count_1 << " " << count_2 << " " << count_3 << endl;
//     }
// }