#include <bits/stdc++.h>
using namespace std;
struct Process
{
    int id, arrival_time, burst_time, remaining_time, completion_time,
        turnaround_time, waiting_time, start_time;
    bool started = false;
};
int findShortestRemainingJob(vector<Process> &processes, int current_time)
{
    int min_index = -1, min_time = INT_MAX;
    for (int i = 0; i < processes.size(); i++)
    {
        if (processes[i].arrival_time <= current_time &&
            processes[i].remaining_time > 0)
        {
            if (processes[i].remaining_time < min_time)
            {
                min_time = processes[i].remaining_time;
                min_index = i;
            }
        }
    }
    return min_index;
}

void calculateTimes(vector<Process> &processes)
{
    int n = processes.size();
    int completed = 0, current_time = 0;

    while (completed < n)
    {
        int index = findShortestRemainingJob(processes, current_time);

        if (index == -1)
        {
            current_time++;
            continue;
        }

        if (!processes[index].started)
        {
            processes[index].start_time = current_time;
            processes[index].started = true;
        }

        processes[index].remaining_time--;
        current_time++;

        if (processes[index].remaining_time == 0)
        {
            processes[index].completion_time = current_time;
            processes[index].turnaround_time =
                processes[index].completion_time - processes[index].arrival_time;
            processes[index].waiting_time = processes[index].turnaround_time -
                                            processes[index].burst_time;
            completed++;
        }
    }
}

void printResults(const vector<Process> &processes)
{
    double total_tat = 0, total_wt = 0;
    int n = processes.size();

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto &p : processes)
    {
        cout << p.id << "\t" << p.arrival_time << "\t" << p.burst_time << "\t"
             << p.completion_time << "\t" << p.turnaround_time << "\t" << p.waiting_time << "\n";
        total_tat += p.turnaround_time;
        total_wt += p.waiting_time;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << (total_tat / n) << endl;
    cout << "Average Waiting Time: " << (total_wt / n) << endl;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculateTimes(processes);
    printResults(processes);

    return 0;
}