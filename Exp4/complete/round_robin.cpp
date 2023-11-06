#include <iostream>
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
    void round_robin(int, sequencing[]);
    void output(int);
       int minimum(int,sequencing[]);
};
#define max 200
int queue[max];
int front=-1;
int rear=-1;
int isempty();
int isfull();
int del();
void insert(int);
#define pending 1
#define finished 2
#define queued 3
void sequencing::input(int i)
{
    cout << "\n<<  P[" << i + 1 << "]  >>\nBURST TIME : ";
    cin >> burst_time;
    cout << "ARRIVAL TIME : ";
    cin >> arrival_time;
    status=pending;
    remaining_time=burst_time;
}
void sequencing::output(int i)
{
    cout << "P[" << i + 1 << "]    \t" << burst_time << "\t\t" << arrival_time << "\t    " << waiting_time << "\t\t" << turnaround_time << endl;
}
void sequencing::round_robin(int n, sequencing p[])
{
    int total_time = minimum(n,p), k = 0,time_lapse;
	cout<<"enter the time lapse : ";
	cin>>time_lapse;
    for(int i=0;i<n;i++)
    if(p[i].arrival_time==total_time)
    {
    p[i].status=queued;
    insert(i);
	}
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    cout << "GANTT CHART : "<<total_time;
    while(!isempty())
    {
        int j;
        k=del();
        p[k].status=pending;
        int time;
        time=p[k].remaining_time<time_lapse?p[k].remaining_time:time_lapse;
        for(j=0;j<time;j++)
        {
            for(int l=0;l<n;l++)
            {
                if(l!=k && p[l].status==pending)
                {
                    if(p[l].arrival_time==total_time + j)
                    {
                        insert(l);
                        p[l].status=queued;
                    }
                }
            }
        }
            total_time+=j;
        	p[k].remaining_time-=j;
        if(p[k].remaining_time==0)
        {
            p[k].status=finished;
            p[k].turnaround_time = total_time - p[k].arrival_time;
            avg_turnaround_time += p[k].turnaround_time;
            p[k].waiting_time= p[k].turnaround_time-p[k].burst_time;
            avg_waiting_time += p[k].waiting_time;
        }
        else
        {
            insert(k);
            p[k].status=queued;
        }
        for(int i=0;i<n;i++)
        {
        	if(p[i].status==pending && p[i].arrival_time==total_time)
        	insert(i);
        	p[i].status=queued;
		}
            cout << "|__P[" << k + 1 << "]__|" << total_time;
            int if_finished=0;
        for(int i=0;i<n;i++)
            if(p[i].status==pending || p[i].status==queued)
            if_finished=1;
        if(!if_finished)
        break;
    }
cout << "|";
cout << "\nAVERAGE WAITING TIME : " << avg_waiting_time / n;
cout << "\nAVERAGE TURN AROUND TIME : " << avg_turnaround_time / n << endl;
}
int sequencing::minimum(int n,sequencing p[])
{
    int  min=9999;
    for(int i=0;i<n;i++)
    if(p[i].arrival_time<min)
    min=p[i].arrival_time;
    return min;
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF JOBS : ";
    cin >> n;
    sequencing *p;
    p = new sequencing[n];
    for (int i = 0; i < n; i++)
        p[i].input(i);
    sequencing x;
    x.round_robin(n, p);
    cout << "\nProcess   BURST_Time   Arrival_Time  Waiting_Time Turnaround_Time:\n";
    for (int i = 0; i < n; i++)
        p[i].output(i);
    return 0;
}
int isempty()
{
	if(front==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(front==(rear+1)%max)
	return 1;
	else
	return 0;
}
void insert(int a)
{
	if(!isfull())
	{

		queue[++rear]=a;
		if(front==-1)
		front=0;
		if(rear==max)
		rear=0;
	}
	else
	{
		printf("queue is full...\n");
	}
}
int del()
{
	if(!isempty())
	{
		int x;
		x=front;
		if(front==rear)
		{
		  front=rear=-1;
		}
		else
		front++;

		return queue[x];
	}
}
