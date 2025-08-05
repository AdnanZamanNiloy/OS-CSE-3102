#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int burst,waiting,remaining,turnaround;
};

int main()
{
    int n, td;
    cin >> n>>td;
    vector<Process> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
    }

    queue<int> queue;
    int curtime = 0;
    int completed = 0;

    for (int i = 0; i < n; i++)
        queue.push(i);
    

    // cout << "\nExecution Order:\n";
    while (completed < n)
    {
        if (queue.empty()== true)
            
        {
            curtime++;
            continue;
        }

        int cur = queue.front();
        queue.pop();

        int execution = min(td, p[cur].remaining);

        // cout << "Process " << p[cur].name << " executes from time "
        //      << curtime << " to " << curtime + execution << endl;

        p[cur].remaining -= execution;
        curtime += execution;

        if (p[cur].remaining == 0)
        {
            completed++;
            p[cur].turnaround = curtime;
            p[cur].waiting = p[cur].turnaround - p[cur].burst;
        }
        else
            queue.push(cur);
        
    }

    cout << "\nProcess\tBurst\tWaiting\tTurnaround\n";
    int total_waiting = 0;
    int total_turnaround = 0;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].name << "\t" << p[i].burst << "\t"
             << p[i].waiting << "\t" << p[i].turnaround << endl;

        total_waiting += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << (double)total_waiting / n << endl;
    cout << "Average Turnaround Time: " << (double)total_turnaround / n << endl;

    return 0;
}

/*
Sample Input:
5 2
p1 10
p2 1
p3 2
p4 1
p5 5
*/
