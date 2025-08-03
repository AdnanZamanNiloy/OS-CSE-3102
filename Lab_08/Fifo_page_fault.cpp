#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fs,len;
    cin >> fs>>len;

    vector<int> pages(len);

    for (int i = 0; i < len; i++)
        cin >> pages[i];

    queue<int> q;
    int faults = 0;
    set<int> frame;

    for (int page : pages)
    {
        if (frame.find(page) == frame.end())
        {
            faults++;
            if (frame.size() == fs)
            {
                int removed = q.front();
                q.pop();
                frame.erase(removed);
            }
            frame.insert(page);
            q.push(page);
        }
    }
    double miss_ratio = (double)faults / len;
    double hit_ratio = 1 - miss_ratio;
    cout << "Miss Ratio: " << miss_ratio * 100 << "%" << endl;
    cout << "Hit Ratio: " << hit_ratio * 100 << "%" << endl;
    cout << "Total Page Faults-fifo: " << faults << endl;

    return 0;
}

/* input
3
11
0 1 2 0 3 0 4 2 3 0 3
*/
