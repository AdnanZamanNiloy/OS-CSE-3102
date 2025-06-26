#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int arrival, burst, waiting;
};

int main()
{
    int n;
   
    cin >> n;
    vector<Process> p(n);
    
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].name >> p[i].arrival >> p[i].burst;
    }
   
    sort(p.begin(), p.end(), [](const Process &a, const Process &b)
         { return a.arrival < b.arrival; });

    int current_time = 0;
    double total_waiting = 0;
    cout << "Process\tArrival\tBurst\tWaiting\n";
    for (int i = 0; i < n; ++i)
    {
        if (current_time < p[i].arrival)
            current_time = p[i].arrival;
        p[i].waiting = current_time - p[i].arrival;
        total_waiting += p[i].waiting;
        cout << p[i].name << "\t" << p[i].arrival << "\t" << p[i].burst << "\t" << p[i].waiting << "\n";
        current_time += p[i].burst;
    }
    cout << "Average waiting time: " << fixed << setprecision(2) << total_waiting / n << "\n";
    return 0;
}
/*
input
4
p1 4 10
p2 5 5
p3 8 7
p4 4 9
*/
