#include<iostream>

using namespace std;

void sort(int size, int priority[], int arrival[], int burst[]){
	int var1,var2,var3;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(priority[i]>priority[j])
			{
				var1 = priority[i];
				priority[i] = priority[j];
				priority[j] = var1;

				var2 = arrival[i];
				arrival[i] = arrival[j];
				arrival[j] = var2;

				var3 = burst[i];
				burst[i] = burst[j];
				burst[j] = var3;

			}
		}
	}
}

void driver(int n,int burst[50],int arrival[50],int priority[50])
{
	int turn[50],bt[50],wait[50];
	int check = 0;
	int count = 0;
	float avg_turn = 0.0;
	float avg_wait = 0.0;

	sort(n,priority,arrival,burst);	//sorting arrival time and busrt time on the basis of priority 

	for(int i=0;i<n;i++)
	{
		bt[i] = burst[i];
	}

	while(true)
	{
		if(check==n)
			break;
		for(int i=0;i<n;i++)
		{
			if(bt[i]==0)
				continue;

			if((arrival[i]<=count))
			{
				count = count + bt[i];
				bt[i] = 0;
				turn[i] = count;
				check = check + 1;
				break;
            }
		}
	}

	for(int i=0;i<n;i++)
	{
		turn[i] = turn[i] - arrival[i];
	}

	for(int i=0;i<n;i++)
	{
		wait[i] = turn[i] - burst[i];
	}

	cout<<endl;
	cout<<"Process\tPriority\tArrival time\tBurst time\tWaiting time\tTurnaround time"<<endl;

	for(int i=0;i<n;i++)
	{
		avg_wait+=wait[i];
		avg_turn+=turn[i];
        cout<<"P("<<i+1<<")-\t\t"<<priority[i]<<"\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<wait[i]<<"\t\t"<<turn[i]<<endl;
	}

	cout<<"The average wait time for all processes is: "<<(avg_wait/n)<<endl;
	cout<<"The average turnaround time for all processes is: "<<(avg_turn/n)<<endl;
}

int main()
{
	int processes,burst[50],arrival[50],priority[50];
	cout<<"Enter the total number of processes:"<<endl;
	cin>>processes;
	cout<<"Enter the arrival time for all processes: "<<endl;
	for(int i=0;i<processes;i++)
	{
		cout<<"Enter arrival time: ";
		cin>>arrival[i];
	}
    cout<<"Enter the burst time for all processes: "<<endl;
    for(int i=0;i<processes;i++)
    {
    	cout<<"Enter burst time: ";
    	cin>>burst[i];
    }
    cout<<"Enter the priority for all processes: "<<endl;
    for(int i=0;i<processes;i++)
    {
    	cout<<"Enter priority: ";
    	cin>>priority[i];
    }
    driver(processes,burst,arrival,priority);	//driver function to calculate wait and turnaround time
    return 0;
}