#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 999
typedef struct
{
    int pid;
    int at;
    int bt;
} process;
void wait_time(process *p, int n, int *wt)
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = p[i].bt;
    int complete = 0, t = 0, minm = MAX, shortest = 0, finish_time, prev = -1, time = 0;
    bool check = false;
    cout << endl
         << "Gantt Chart" << endl
         << "|";
    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((p[j].at <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;

                check = true;
            }
        }
        if (check == false)
        {
            t++;
            continue;
        }
        if (prev != shortest)
            cout << time << " | P" << shortest + 1 << " | ";
        time++;
        prev = shortest;
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = MAX;
        if (rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - p[shortest].bt - p[shortest].at;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
    cout << time << endl
         << endl;
}
void turnaround_time(process *p, int n, int *wt, int *tat)
{
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wt[i];
}
int psrt(process *p, int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wait_time(p, n, wt);
    turnaround_time(p, n, wt, tat);
    cout << " Process\t BT\t\t AT\t\t WT\t\t TAT\t\t\n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << p[i].pid << "\t\t " << p[i].bt << "\t\t " << p[i].at << "\t\t " << wt[i] << "\t\t " << tat[i] << "\t\t" << endl;
    }
    cout << "\nAverage waiting time = " << ((float)total_wt / (float)n);
    cout << "\nAverage Turn_around time = " << ((float)total_tat / (float)n) << endl;
}
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    process p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "For process " << i + 1 << endl;
        cout << "Enter burst time: ";
        cin >> p[i].bt;
        cout << "Enter arrival time: ";
        cin >> p[i].at;
        p[i].pid = i + 1;
    }
    cout << endl
         << endl;
    psrt(p, n);
    return 0;
}