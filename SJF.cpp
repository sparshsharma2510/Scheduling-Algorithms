#include<iostream>

using namespace std;

void sort(int size, int burst[], int arrival[]){
	int var1, var2;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(burst[i]>burst[j])
			{
				var1 = burst[i];
				burst[i] = burst[j];
				burst[j] = var1;

				var2 = arrival[i];
				arrival[i] = arrival[j];
				arrival[j] = var2;
			}
		}
	}
}

void sjf(int n,int burst[50],int arrival[50])
{
	int turn[50],bt[50],at[50],wait[50];
	int check = 0;
	float avg_turn = 0.0;
	float avg_wait = 0.0;
	int var1,var2,temp;

    for(int i=0;i<n;i++)
    {
    	at[i] = arrival[i];
    }

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
				temp = at[i];
				at[i] = at[j];
				at[j] = temp;
			}
		}
	}

	int count = at[0];

	sort(n,burst,arrival);	//sorting on the basis of burst time
	
	for(int i=0;i<n;i++)
	{
		bt[i] = burst[i];
	}

	while(true)
	{
		if(check == n)
			break;
        for(int i=0;i<n;i++)
	    {
		   if((arrival[i]<=count) && (bt[i]!=0))
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
	cout<<"Process\t\tArrival time\tBurst time\tWaiting time\tTurnaround time"<<endl;

	for(int i=0;i<n;i++)
	{
		avg_wait+=wait[i];
		avg_turn+=turn[i];
        cout<<"P("<<i<<")-\t\t"<<arrival[i]<<"\t\t"<<burst[i]<<"\t\t"<<wait[i]<<"\t\t"<<turn[i]<<endl;
	}

	cout<<"The average wait time for all processes is: "<<(avg_wait/n)<<endl;
	cout<<"The average turnaround time for all processes is: "<<(avg_turn/n)<<endl;
}

int main()
{
	int processes,burst[50],arrival[50];
	cout<<"Enter the total number of processes:"<<endl;
	cin>>processes;
	cout<<"Enter the arrival time for all processes:"<<endl;
	for(int i=0;i<processes;i++)
	{
		cout<<"Enter arrival time: ";
    	cin>>arrival[i];
	}
	cout<<"Enter the burst time for all processes:"<<endl;
	for(int i=0;i<processes;i++)
	{
		cout<<"Enter burst time: ";
    	cin>>burst[i];
	}
	sjf(processes,burst,arrival);
}