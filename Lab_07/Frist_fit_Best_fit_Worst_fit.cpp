#include <bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    fill(allocation, allocation + processes, -1);

    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < processes; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    fill(allocation, allocation + processes, -1);

    for (int i = 0; i < processes; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < processes; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    fill(allocation, allocation + processes, -1);

    for (int i = 0; i < processes; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < processes; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int blocks, processes;
    cin >> blocks;
    int blockSize[blocks];

    for (int i = 0; i < blocks; i++)
    {
        cin >> blockSize[i];
    }

    cin >> processes;
    int processSize[processes];
    for (int i = 0; i < processes; i++)
    {
        cin >> processSize[i];
    }

    int blockSize1[blocks], blockSize2[blocks], blockSize3[blocks];
    copy(blockSize, blockSize + blocks, blockSize1);
    copy(blockSize, blockSize + blocks, blockSize2);
    copy(blockSize, blockSize + blocks, blockSize3);

    firstFit(blockSize1, blocks, processSize, processes);
    bestFit(blockSize2, blocks, processSize, processes);
    worstFit(blockSize3, blocks, processSize, processes);

    return 0;
}
/*
input
5
100
500
200
300
600
4
212
417
112
426
*/
