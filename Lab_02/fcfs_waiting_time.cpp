#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> burst(n);
    for (int i = 0; i < n; i++)
        cin >> burst[i];
    vector<int> waiting(n, 0);
    for (int i = 1; i < n; i++)
        waiting[i] = waiting[i - 1] + burst[i - 1];

    int total_waiting = 0;
    for (int i = 0; i < n; i++)
        total_waiting += waiting[i];
    double avg_waiting = (double)total_waiting / n;
    for (int i = 0; i < n; i++)
        cout << "Process " << i + 1 << ": Waiting time = " << waiting[i] << '\n';

    cout << "Average waiting time: " << fixed << setprecision(2) << avg_waiting << '\n';
}
/*
input:
5
1 2 3 4 5
*/
