
#include <bits/stdc++.h>
using namespace std;

class TASK{
    string TaskName;
    int BurstTime;
    int WaitingTime;
    int TotalAverageTime;
    
    public : 
             TASK(string name = "DEFAULT",int time = 0) : TaskName(name) , BurstTime(time) {}
             TASK getTask(){return *this;}
             string getTaskName(){return TaskName;} 
             int getTaskTime(){return BurstTime;}
             void setWaitingTime(int time){ this->WaitingTime = time; }
             void setTotalAverageTime(int time){this->TotalAverageTime = time;}

};

int main()
{
    
    return 0;    
}