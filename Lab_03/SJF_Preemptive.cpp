#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string id;
    int arrival;
    int burst;
    int remaining;
    int waiting = 0;
    int turn = 0;
    int completion = 0;
    bool completed = false;
};

int main()
{
    int n = 5;
    vector<Process> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].id >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int complete = 0, current_time = 0;
    float total_wait = 0, total_turn = 0;

    while (complete < n)
    {
        int shortest = -1;
        int min_remain = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!p[i].completed && p[i].arrival <= current_time && p[i].remaining < min_remain)
            {
                min_remain = p[i].remaining;
                shortest = i;
            }
        }

        if (shortest == -1)
        {
            current_time++;
            continue;
        }

       
        p[shortest].remaining--;
        current_time++;

        if (p[shortest].remaining == 0)
        {
            p[shortest].completion = current_time;
            p[shortest].turn = p[shortest].completion - p[shortest].arrival;
            p[shortest].waiting = p[shortest].turn - p[shortest].burst;
            p[shortest].completed = true;

            total_wait += p[shortest].waiting;
            total_turn += p[shortest].turn;
            complete++;
        }
    }

    cout << "Process\tArrival\tBurst\tCompletion\tWaiting\tturn\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t"
             << p[i].arrival << "\t"
             << p[i].burst << "\t"
             << p[i].completion << "\t\t"
             << p[i].waiting << "\t"
             << p[i].turn << endl;
    }

    cout << "\nAverage Waiting Time: " << total_wait / n << endl;
   
    return 0;

}
/* input
p1 0 12
p2 1 3
p3 2 5
p4 3 8
p5 4 2
*/
