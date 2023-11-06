#include<iostream>
#include<iomanip>
#define size 20
#define queue_size 30
#define MAX 30
using namespace std;
int queue[queue_size], front=-1,rear=-1;

void insert(int k){
	if(front==-1)
		front=0;
	rear= (rear+1)%queue_size;
	queue[rear]=k;
}

int del(){
	int k=queue[front];
	if(front==rear){
		front=-1;
		rear=-1;
	}
	else
		front = (front+1)%queue_size;
	return k;
}

float average(int *matrix,int n){
	float avg = 0.0;
	for(int i=0;i<n;i++)
		avg += matrix[i];
	return avg/n;
}

void RoundRobin(int n, int burst[], int arrival[],int quantum){
	int rem_burst[n+1], WT[n], TAT[n],completion[n]; 
	int totaltime=0;
	for(int i=0; i<n; i++){
		rem_burst[i] = burst[i];
		totaltime+=burst[i] ;
	}
	int temp_process[totaltime] = {0}, temp_time[totaltime]={0}, arrived_process[n]={0};
	int k=0,tracker,next=-1;
	for(int time=0; time<totaltime; time++){
		for(int i=0;i<n;i++){
			if(arrival[i]<=time && arrived_process[i]==0){
				insert(i);
				arrived_process[i]=1;
			} 
		}
		if(next==-1){
			next=del();
			temp_process[k] = next;
			tracker=0;
		}

		if(tracker!=quantum && rem_burst[next]>0){
			rem_burst[next]--;
			tracker++;
			if(tracker!=quantum && rem_burst[next]>0)
				continue;
		}

		temp_time[k++]=time+1;

		if(rem_burst[next]==0){
			completion[next] = time+1;
			TAT[next] = completion[next] - arrival[next];
			WT[next] = TAT[next] - burst[next]; 
			next=-1;
		}
		else{
			insert(next);
			next=-1;
		}
	}
	
	cout<<endl<<"Gantt Chart:"<<endl;
	cout<<"-----0"<<endl;
	for(int i = 0; i < k; i++){
 		cout<<" P"<<temp_process[i]<<endl;
 		cout<<"-----"<<temp_time[i]<<endl;
 	} 
 
	cout<<endl<<"Process"<<setw(size)<<"Burst Time"<<setw(size)<<"Arrival Time"<<setw(size)<<"Turnaround Time"<<setw(size)<<"Waiting Time"<<endl;
	for(int i=0;i<n;i++){
		cout<<"P"<<i<<setw(size)<<burst[i]<<setw(size)<<arrival[i]<<setw(size)<<TAT[i]<<setw(size)<<WT[i]<<endl;
	}
	cout<<endl<<"Average waiting time : "<<average(WT,n);
	cout<<endl<<"Average turn-around time : "<<average(TAT,n);
}

int main()
{
	int n, quantum; 
	cout<<"Enter the number of processes: ";
	cin>>n;
	int burst[n], arrival[n];
	for(int i=0;i<n;i++){
		cout<<"Process "<<i+1<<endl;
		cout<<"Enter Burst Time: ";
		cin>>burst[i];
		cout<<"Enter Arrival Time: ";
		cin>>arrival[i];
	}
	cout<<"Enter the time quantum: ";
	cin>>quantum;
	RoundRobin(n,burst,arrival,quantum);
}