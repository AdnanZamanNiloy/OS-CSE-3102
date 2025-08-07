#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len, fs;
    cin >> fs >> len;

    vector<int> pages(len);
    for (int i = 0; i < len; i++)
        cin >> pages[i];

    set<int> frames;
    map<int, int> lused;
    int faults = 0;
    vector<int> v;
    for (int i = 0; i < len; ++i)
    {
        int page = pages[i];
        cout << "Page: " << page;
        if (frames.find(page) == frames.end())
        {
            faults++;
            if (frames.size() < fs)
                v.push_back(page);

            if (frames.size() == fs)
            {

                int last_used = i;
                int remove = -1;

                for (int f : frames)
                {
                    if (lused[f] < last_used)
                    {
                        last_used = lused[f];
                        remove = f;
                    }
                }
                frames.erase(remove);
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[j] == remove)
                    {
                        v[j] = page;
                        break;
                    }
                }
            }

            frames.insert(page);
        }
        lused[page] = i;
        cout << " Frames: ";
        for (auto f : v)
            cout << f << " ";
        cout << endl;
    }

    double miss_ratio = (double)faults / len;
    double hit_ratio = 1 - miss_ratio;
    cout << "Miss Ratio: " << miss_ratio * 100 << "%" << endl;
    cout << "Hit Ratio: " << hit_ratio * 100 << "%" << endl;
    cout << "Total Page Faults-lru: " << faults << endl;
    return 0;
}
/*
3
11
0 1 2 0 3 0 4 2 3 0 3
*/
