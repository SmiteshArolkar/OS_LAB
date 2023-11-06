#include <bits/stdc++.h>
#include "Process.h"
using namespace std;



void FCFS(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrival_time > p[j + 1].arrival_time)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}


void StartProcessing(Process p[], int n)
{

    p[0].waiting_time = 0;
    p[0].completion_time = p[0].burst_time;


    for (int i = 1; i < n; i++)
    {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time + p[i - 1].arrival_time - p[i].arrival_time;
    }

    
    for (int i = 1; i < n; i++)
    {
        p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
    }

    for (int i = 0; i < n; i++)
    {
        p[i].turn_around_time = p[i].waiting_time + p[i].burst_time;
    }
}

void DisplayGantChart(Process p[], int n)
{
    cout<<"Gant Chart\n";
    for(int i=0;i<n;i++)
    {
        cout<<"|\t"<<"P"<<p[i].pid<<"\t";
    }

    cout<<"|\n"<<"0"<<"\t\t";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<p[i].completion_time<<"\t\t";
    }
}

void ShowProcessQueue(Process p[], int n)
{
    cout << "Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnAround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t\t" << p[i].burst_time << "\t\t" << p[i].arrival_time << "\t\t" << p[i].waiting_time << "\t\t" << p[i].turn_around_time  << endl;
    }
}

int main()
{
    cout << "FCFS Enter Number of Process\n";
    int n;
    cin >> n;
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "Enter Burst Time and Arrival time for Process " << i + 1 << endl;
        cin >> p[i].burst_time >> p[i].arrival_time;
    }

    FCFS(p, n);
    StartProcessing(p, n);
    cout<<endl;
     DisplayGantChart(p,n);
     cout<<endl;

    float average_wt = 0, average_tat = 0;
    for (int i = 0; i < n; i++)
    {
        average_wt += p[i].waiting_time;
        average_tat += p[i].turn_around_time;
    }

    average_tat /= (float)n;
    average_wt /= (float)n;
    ShowProcessQueue(p, n);
    cout<<"Average Waiting Time : "<<average_wt<<endl;
    cout<<"Average TurnAround Time : "<<average_tat<<endl;

   
}