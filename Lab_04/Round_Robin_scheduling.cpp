#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void roundRobinScheduling(vector<Process> &processes, int time_quantum)
{
    queue<Process *> ready_queue;
    int current_time = 0;
    int completed = 0;
    int n = processes.size();

    for (auto &p : processes)
    {
        p.remaining_time = p.burst_time;
        ready_queue.push(&p);
    }

    while (!ready_queue.empty())
    {
        Process *current = ready_queue.front();
        ready_queue.pop();

        int execution_time = min(time_quantum, current->remaining_time);
        current->remaining_time -= execution_time;
        current_time += execution_time;

        int queue_size = ready_queue.size();
        for (int i = 0; i < queue_size; i++)
        {
            Process *p = ready_queue.front();
            ready_queue.pop();
            p->waiting_time += execution_time;
            ready_queue.push(p);
        }

        if (current->remaining_time > 0)
        {
            ready_queue.push(current);
        }
        else
        {
            completed++;
            current->turnaround_time = current_time;
        }
    }
}

void printResults(const vector<Process> &processes)
{
    cout << "\nProcess\tBurst\tWaiting\tTurnaround\n";
    int total_waiting = 0;
    int total_turnaround = 0;

    for (const auto &p : processes)
    {
        cout << p.name << "\t" << p.burst_time << "\t"
             << p.waiting_time << "\t" << p.turnaround_time << endl;

        total_waiting += p.waiting_time;
        total_turnaround += p.turnaround_time;
    }

    float avg_waiting = static_cast<float>(total_waiting) / processes.size();
    float avg_turnaround = static_cast<float>(total_turnaround) / processes.size();

    cout << "\nAverage Waiting Time: " << avg_waiting << endl;
    cout << "Average Turnaround Time: " << avg_turnaround << endl;
}

int main()
{
    int n, time_quantum;

    cin >> n >> time_quantum;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].name >> processes[i].burst_time;
    }

    roundRobinScheduling(processes, time_quantum);
    printResults(processes);

    return 0;
}
/*
5 2
p1 10
p2 1
p3 2
p4 1
p5 5
*/
