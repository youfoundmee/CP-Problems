#include <iostream>
using namespace std;
const int P = 5; 
const int R = 3; 
void calculateNeed(int need[P][R], int max[P][R], int allocation[P][R])
{
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
bool isSafe(int processes[], int avail[], int max[][R], int allocation[][R])
{
    int need[P][R];
    calculateNeed(need, max, allocation);
    bool finish[P] = {false};
    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R; i++)
    {
        work[i] = avail[i];
    }
    int count = 0;
    while (count < P)
    {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            if (!finish[p])
            {
                bool canAllocate = true;
                for (int j = 0; j < R; j++)
                {
                    if (need[p][j] > work[j])
                    {
                        canAllocate = false;
                        
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < R; j++)
                    {
                        work[j] += allocation[p][j];
                    }
                    safeSeq[count++] = processes[p];
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "System is in an unsafe state.\n";
            return false;
        }
    }
    cout << "System is in a safe state. Safe sequence is: ";
    for (int i = 0; i < P; i++)
    {
        cout << "P" << safeSeq[i] << " ";
    }
    cout << endl;
    return true;
}
int main()
{
    int processes[] = {0, 1, 2, 3, 4};
    int available[] = {3, 3, 2};
    int max[][R] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allocation[][R] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    isSafe(processes, available, max, allocation);
    return 0;
}