#include<iostream>
using namespace std;
class banker
{
    int allocated[10];
    int maximum[10];
    int need[10];
    int status;
    public:
    void input(int,int);
    //void output(int);
    void banker_algo(int,int,banker []);
};
#define finished 2
#define pending 1
void banker::input(int m,int j)
{
    cout<<"\n\nPROCESS 'P["<<j+1<<"]' \n";
    cout<<"\n Allocated \n";
    for(int i=0;i<m;i++)
    {
        cout<<"Resource 'R["<<i+1<<"]' :";
        cin>>allocated[i];
    }
    cout<<"\n Max needed \n";
    for(int i=0;i<m;i++)
    {
        cout<<"Resource 'R["<<i+1<<"]' : ";
        cin>>maximum[i];
    }
    cout<<"\n\n";
}

void banker::banker_algo(int m,int n,banker process[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            process[i].need[j]=process[i].maximum[j]-process[i].allocated[j];
        }
        process[i].status=pending;
    }
    int half=m/2;
    int i=0,j=0,k=1,z=0;
    int no_allocation=1,sequence[n+2];
    int available[m+1];
    int available_mat[n+1][m+1];
    cout<<" Instances available \n";
    for(int l=0;l<m;l++)
    {
    cout<<"R["<<l+1<<"] : ";
    cin>>available[l];
    available_mat[0][l]=available[l];
    }
    while(no_allocation)
    {
        if(j==n)
        j=0;
        int l;
        int checkhalf=0;
        for(l=0;l<m;l++)
        {
            if(process[j].need[l]>available[l])
            break;
            else if(process[j].need[l]==available[l])
            {
                if(checkhalf<half)
                checkhalf++;
                else
                break;
            }
        }
        if(l==m && process[j].status==pending)
        {
            z=0;
            sequence[i++]=j;

            for(int a=0;a<m;a++)
            {
                available[a]+=process[j].allocated[a];
                available_mat[k][a]=available[a];
            }
            process[j].status=finished;
            k++;
            if(i==n)
            no_allocation=0;
        }
        else
        {
        z++;
        }
        if(z>n)
        {
            no_allocation=0;
        }
        j++;
    }
    if(i<n)
    {
    cout<<"\n\nBANKERS ALGORITHM SAYS : 'POSSIBILITY OF A DEADLOCK ' \n";
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            available_mat[n][i]=available_mat[n-1][i]+process[sequence[n-1]].allocated[i];
        }
        cout<<endl;
        cout<<"\n ALLOCATED MATRIX\n ";
        for(int j=0;j<m;j++)
            {
                cout<<"R["<<j<<"]\t";
            }
            cout<<endl;
        for(int k=0;k<n;k++)
        {
            cout<<" ";
            for(int i=0;i<m;i++)
            {
                cout<<process[k].allocated[i]<<" \t";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<" MAXIMUM NEED MATRIX \n ";
        for(int j=0;j<m;j++)
        {
            cout<<"R["<<j<<"]\t";
        }
                    cout<<endl;
        for(int k=0;k<n;k++)
        {
        cout<<" ";
            for(int i=0;i<m;i++)
            {
                cout<<process[k].maximum[i]<<" \t";
            }
                        cout<<endl;
        }
        cout<<endl;
        cout<<" NEED MATRIX\n ";
        for(int j=0;j<m;j++)
        {
            cout<<"R["<<j<<"]\t";
        }
                    cout<<endl;
        for(int k=0;k<n;k++)
        {
        cout<<" ";
            for(int i=0;i<m;i++)
            {
                cout<<process[k].need[i]<<" \t";
            }
                        cout<<endl;
        }
        cout<<endl;
        cout<<" AVAILABLE MATRIX \n ";
        for(int j=0;j<m;j++)
        {
            cout<<"R["<<j<<"]\t";
        }
                    cout<<endl;
        for(int k=0;k<=n;k++)
        {
        cout<<" ";
            for(int i=0;i<m;i++)
            {
                cout<<available_mat[k][i]<<" \t";
            }
                        cout<<endl;
        }
        cout<<endl;
        cout<<"\nALLOCATION SEQUENCE : ";
        for(int i=0;i<n;i++)
        cout<<"P["<<sequence[i]<<"] ";
    }
}

int main()
{
    int n,m;
    cout<<"enter the number of resources : ";
    cin>>m;
    cout<<"Enter the number of processes : ";
    cin>>n;
    banker *process;
    process=new banker[n];
    for(int i=0;i<n;i++)
    {
        process[i].input(m,i);
    }
    banker x;
    x.banker_algo(m,n,process);
    return 0;
}
