#include <iostream>
#include <queue>
using namespace std;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void RoundRobin(Process proc[], int n, int timeQuantum)
{
    queue<int> q;
    int currentTime = 0;
    bool visited[n] = {false};
    int remaining = n;

    // Enqueue the first process
    for (int i = 0; i < n; i++)
    {
        proc[i].remainingTime = proc[i].burstTime;
    }

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        if (proc[i].remainingTime > timeQuantum)
        {
            currentTime += timeQuantum;
            proc[i].remainingTime -= timeQuantum;
        }
        else
        {
            currentTime += proc[i].remainingTime;
            proc[i].completionTime = currentTime;
            proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
            proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
            proc[i].remainingTime = 0;
            remaining--;
        }

        // Check for new arrivals
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && proc[j].arrivalTime <= currentTime)
            {
                q.push(j);
                visited[j] = true;
            }
        }

        // If the process is not done, add it back to the queue
        if (proc[i].remainingTime > 0)
        {
            q.push(i);
        }
    }

    cout << "\nRound Robin Scheduling (Time Quantum = " << timeQuantum << "):\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << "\t" << proc[i].arrivalTime << "\t" << proc[i].burstTime
             << "\t" << proc[i].completionTime << "\t" << proc[i].turnaroundTime
             << "\t" << proc[i].waitingTime << "\n";
    }
}

int main()
{
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    Process proc[n];

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        cout << "Process " << i + 1 << " - Arrival Time: ";
        cin >> proc[i].arrivalTime;
        cout << "Process " << i + 1 << " - Burst Time: ";
        cin >> proc[i].burstTime;
    }

    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    RoundRobin(proc, n, timeQuantum);
    return 0;
}
