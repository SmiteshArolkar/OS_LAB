class Process
{
public:
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turn_around_time;
    int completion_time;
    int priority;
    Process(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0,int g = 0) : pid(a), burst_time(b), arrival_time(c), waiting_time(d), turn_around_time(e), completion_time(f) , priority(g) {}
};