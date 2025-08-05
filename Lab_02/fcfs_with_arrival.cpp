#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int burst, arrival, waiting, inputSerial;
};

int main()
{
    int n;
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].name >> p[i].burst >> p[i].arrival;
        p[i].inputSerial = i;
    }

    // Sort by arrival time, then by input order
    sort(p.begin(), p.end(), [](const Process &a, const Process &b)
         {
        if (a.arrival != b.arrival)
            return a.arrival < b.arrival;
        return a.inputSerial < b.inputSerial; });

    int currentime = 0;
    int totalWaitingTime = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i].arrival > currentime)
            currentime = p[i].arrival;

        p[i].waiting = currentime - p[i].arrival;
        totalWaitingTime += p[i].waiting;
        currentime += p[i].burst;
    }
    double averageWaitingTime = (double)totalWaitingTime / n;

    cout << "Process\tArrival\tBurst\tWaiting\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].name << "\t" << p[i].arrival << "\t" << p[i].burst << "\t" << p[i].waiting << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "Average waiting time: " << averageWaitingTime << endl;
}

/*
input
4
p1 4 10
p2 5 5
p3 8 7
p4 4 9
*/
