#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fs, len;
    cin >> fs >> len;
    vector<int> pages(len);

    for (int i = 0; i < len; i++)
        cin >> pages[i];

    set<int> frames;
    int faults = 0, j;

    for (int i = 0; i < len; i++)
    {
        int page = pages[i];
        if (frames.find(page) == frames.end())
        {
            faults++;

            if (frames.size() == fs)
            {
                int farthest = -1;
                int page_to_remove = -1;

                for (int f : frames)
                {
                    int next_use = len;

                    for (j = i + 1; j < len; j++)
                    {
                        if (pages[j] == f)
                        {
                            next_use = j;
                            break;
                        }
                    }

                    if (next_use > farthest)
                    {
                        farthest = next_use;
                        page_to_remove = f;
                    }
                }

                frames.erase(page_to_remove);
            }

            frames.insert(page);
        }
    }

    double miss_ratio = (double)faults / len;
    double hit_ratio = 1 - miss_ratio;
    cout << "Miss Ratio: " << miss_ratio * 100 << "%" << endl;
    cout << "Hit Ratio: " << hit_ratio * 100 << "%" << endl;
    cout << "Total Page Faults-Optimal: " << faults << endl;
    return 0;
}
/*3
11
0 1 2 0 3 0 4 2 3 0 3
  */
