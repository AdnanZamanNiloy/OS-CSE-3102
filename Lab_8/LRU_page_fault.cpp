#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len, fs;
    cin >> fs>>len;
    
    vector<int> pages(len);
    for (int i = 0; i < len; i++)
        cin >> pages[i];

    set<int> frames;
    map<int, int> lused;
    int faults = 0;

    for (int i = 0; i < len; ++i)
    {
        int page = pages[i];
        if (frames.find(page) == frames.end())
        {
            faults++;

            if (frames.size() == fs)
            {
                int last_used = i;
                int m = -1;

                for (int f : frames)
                {
                    if (lused[f] < last_used)
                    {
                        last_used = lused[f];
                        m = f;
                    }
                }
                frames.erase(m);
            }

            frames.insert(page);
        }
        lused[page] = i;
    }
    
    double miss_ratio = (double)faults / len;
    double hit_ratio = 1 - miss_ratio;
    cout << "Miss Ratio: " << miss_ratio*100<<"%"<<endl;
    cout << "Hit Ratio: " << hit_ratio*100<<"%"<<endl;
    cout << "Total Page Faults-lru: " << faults << endl;
    return 0;
}
/*
3
11
0 1 2 0 3 0 4 2 3 0 3
*/
