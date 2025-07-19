#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; // n = number of processes, m = number of resources
    cin >> n >> m;

    int alloc[n][m], max[n][m], avail[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    for (int i = 0; i < m; i++)
        cin >> avail[i];

    int safeseq[n], idx = 0;
    vector<int> f(n, 0);

    int need[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    safeseq[idx] = i;
                    idx++;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            cout << "The system is not in a safe state.\n";
            return 0;
        }
    }

    cout << "The system is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < n - 1; i++)
        cout << "P" << safeseq[i] << " -> ";
    cout << "P" << safeseq[n - 1] << endl;

    return 0;
}
/*-------input----------
5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
*/
