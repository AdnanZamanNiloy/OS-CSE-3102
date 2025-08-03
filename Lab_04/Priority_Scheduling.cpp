#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int burst_time;
    int priority;
    int waiting_time;
};

bool comparePriority(const Process &a, const Process &b)
{
    return a.priority < b.priority;
}

int main()
{
    int n;
    cin >> n;
    vector<Process> processes(n);

    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].name >> processes[i].burst_time >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), comparePriority);

    int current_time = 0;
    int total_waitingtime = 0;
    for (int i = 0; i < n; i++)
    {
        processes[i].waiting_time = current_time;
        total_waitingtime += processes[i].waiting_time;
        current_time += processes[i].burst_time;
    }

    cout << "Process\tWaiting Time\n";
    for (const auto &p : processes)
    {
        cout << p.name << "\t" << p.waiting_time << endl;
    }

    cout << "average waiting time: " << fixed << setprecision(2) << (float)total_waitingtime / n << endl;

    return 0;
}
/*
5
p1 10 3
p2 1  1
p3 2  3
p4 1  4
p5 5  2
  */
