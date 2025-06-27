#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int arrival, burst, start, finish, waiting;
    bool done = false;
};

int main()
{

    int n = 5;
    vector<Process> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].name >> p[i].arrival >> p[i].burst;

    int completed = 0, currentTime = 0;
    float totalWaiting = 0;

    while (completed < n)
    {
        int idx = -1, minBurst = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (!p[i].done && p[i].arrival <= currentTime && p[i].burst < minBurst)
            {
                minBurst = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1)
        {
            currentTime++;
        }
        else
        {
            p[idx].start = currentTime;
            p[idx].finish = p[idx].start + p[idx].burst;
            p[idx].waiting = p[idx].start - p[idx].arrival;
            totalWaiting += p[idx].waiting;
            currentTime = p[idx].finish;
            p[idx].done = true;
            completed++;
        }
    }

    cout << "\nProcess\tArrival\tBurst\tWaiting\n";
    for (auto &proc : p)
    {
        cout << proc.name << "\t" << proc.arrival << "\t" << proc.burst << "\t" << proc.waiting << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << totalWaiting / n << "\n";

    return 0;
}
/*input
p1 0 12
p2 1 3
p3 2 5
p4 3 8
p5 4 2
*/
