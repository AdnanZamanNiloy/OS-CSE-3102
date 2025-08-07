#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fs, len;
    cin >> fs >> len;

    vector<int> pages(len);
    for (int i = 0; i < len; i++)
        cin >> pages[i];

    queue<int> q;            
    set<int> frame;          
    int faults = 0;

    for (int page : pages)
    {
        cout << "Page: " << page;

        
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

        // Print current frame contents
        cout << " Frames: ";
        queue<int> temp = q;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    double miss_ratio = (double)faults / len;
    double hit_ratio = 1 - miss_ratio;

    cout << "Miss Ratio: " << miss_ratio * 100 << "%" << endl;
    cout << "Hit Ratio: " << hit_ratio * 100 << "%" << endl;
    cout << "Total Page Faults (FIFO): " << faults << endl;

    return 0;
}
