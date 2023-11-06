#include <iostream>
#define pending 1
#define finished 2

using namespace std;
class sequencing
{
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int status;

public:
    void input(int);
    void FCFS(int, sequencing[]);
    void output(int);
    int minimum(int, sequencing[]);
};

void sequencing::input(int i)
{
    cout << "\n  P" << i + 1 << "  \nBurst Time : ";
    cin >> burst_time;
    cout << "Arrival Time : ";
    cin >> arrival_time;
    status = pending;
    remaining_time = burst_time;
}
void sequencing::output(int i)
{
    cout << "P[" << i + 1 << "]    \t" << burst_time << "\t\t" << arrival_time << "  \t" << waiting_time << "\t\t" << turnaround_time << endl;
}
void sequencing::FCFS(int n, sequencing p[])
{
    int total_time = minimum(n, p), k = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    cout << "Gantt Chart : " << total_time;
    while (true)
    {
        int rt = 9999;
        for (int j = 0; j < n; j++)
        {
            if (p[j].status == pending && p[j].remaining_time < rt && p[j].arrival_time <= total_time)
            {
                k = j;
                rt = p[j].remaining_time;
            }
        }
        int j, check = 0;
        for (j = 0; j < p[k].remaining_time; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (l != k)
                {
                    if (p[l].arrival_time == total_time + j)
                    {
                        if (p[l].remaining_time < (p[k].remaining_time - j))
                        {
                            check = 1;
                            break;
                        }
                    }
                }
            }
            if (check)
                break;
        }
        total_time += j;
        if (j == p[k].remaining_time)
        {
            p[k].status = finished;
            p[k].turnaround_time = total_time - p[k].arrival_time;
            avg_turnaround_time += p[k].turnaround_time;
            p[k].waiting_time = p[k].turnaround_time - p[k].burst_time;
            avg_waiting_time += p[k].waiting_time;
        }
        else
        {
            p[k].remaining_time -= j;
        }
        cout << "| P" << k + 1 << " |" << total_time;
        int if_finished = 0;
        for (int i = 0; i < n; i++)
            if (p[i].status == pending)
                if_finished = 1;
        if (!if_finished)
            break;
    }
    cout << "|";
    cout << "\nAverage waiting time  : " << avg_waiting_time / n;
    cout << "\nAverage turn around time  : " << avg_turnaround_time / n << endl;
}
int sequencing::minimum(int n, sequencing p[])
{
    int min = 9999;
    for (int i = 0; i < n; i++)
        if (p[i].arrival_time < min)
            min = p[i].arrival_time;
    return min;
}
int main()
{
    int n;
    cout << "Enter number of jobs : ";
    cin >> n;
    sequencing *p;
    p = new sequencing[n];
    for (int i = 0; i < n; i++)
        p[i].input(i);
    sequencing x;
    x.FCFS(n, p);
    cout << "\nProcess   Burst_time   Arrival_Time  Waiting_Time Turnaround_Time:\n";
    for (int i = 0; i < n; i++)
        p[i].output(i);
    return 0;
}
