/*NAME - SPARSH SHARMA
  ROLL NO. - 19573
  B.Sc. Comp. Sci. 2nd Year
  SRJF SCHEDULING ALGORITHM*/

#include <iostream>

using namespace std;

int main(){
	int n,timer=0,ctr = 1,till_Index,minIndex,avgWait = 0, avgTT = 0;
	bool while_break = false;
	cout<<"\nEnter the number of processes : ";
	cin>>n;
	int arrival[n], burst[n], process[n], temp_burst[n],temp_arrive[n], wait[n], turn[n];	//Arrival and burst time arrays declaration;
	process[0] = 1;

	for(int i = 1; i < n; i++)
		process[i] = process[i-1]+1;	//Process index array

	for(int i = 0; i < n; i++){		//Arrival time input loop
		cout<<"\nEnter the arrival time for process "<<i+1<<" : ";
		cin>>arrival[i];
	}

	for(int i = 0; i < n; i++){		//Burst time input loop
		cout<<"\nEnter the burst time for process "<<i+1<<" : ";
		cin>>burst[i];
	}

	for(int i = 0; i < n; i++)
		temp_burst[i] = burst[i];

	for(int i = 0; i < n-1; i++){	//Sorting on the basis of arraival time
		for(int j = i+1; j < n; j++){
			if(arrival[i] > arrival[j]){
				int var = arrival[j];
				arrival[j] = arrival[i];
				arrival[i] = var;

				var = temp_burst[j];
				temp_burst[j] = temp_burst[i];
				temp_burst[i] = var;

				var = process[j];
				process[j] = process[i];
				process[i] = var;
			}
		}
	}

	//PRE-EMPTIVE APPROACH
	while(true){
		bool flag = false;
		for(int i = 0; i < n; i++){
			if(temp_burst[i] != 0)
				flag = true;
		}
		if(!flag)
			break;

		for(int i = 0; i < n; i++){		//index of the last process which has arrived
			if(arrival[i] <= timer)
				till_Index = i;
		}

		int min = 2106791;
		for(int i = 0; i <= till_Index; i++){		//the shortest arrived process index extracted
			if(temp_burst[i] <= min && temp_burst[i] != 0){
				if(temp_burst[i] == min){	//tie-breaker situation
					if(arrival[minIndex] < arrival[i]){
						min = temp_burst[minIndex];
					}
					else{
						min = temp_burst[i];
						minIndex = i;
					}
				}
				else{
					min = temp_burst[i];
					minIndex = i;
				}
			}
		}

		temp_burst[minIndex]--;
		timer++;
		if(temp_burst[minIndex] == 0)
			turn[process[minIndex]-1] = timer; 	//exit time of each process
	}

	for(int i = 0; i < n; i++){
		temp_arrive[process[i]-1] = arrival[i];
	}

	//updating the wait and turn around time
	for(int i = 0; i < n; i++){
		turn[i] = turn[i] - temp_arrive[i];
		wait[i] = turn[i] - burst[i];
	}

	cout<<"\nProgram No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time"<<endl;
	for(int i = 0; i < n; i++){
		cout<<i+1<<"\t\t"<<temp_arrive[i]<<"\t\t"<<burst[i]<<"\t\t"<<wait[i]<<"\t\t"<<turn[i]<<endl;
	}

	for(int i =0; i< n; i++){
		avgWait += wait[i];
		avgTT += turn[i]; 
	}
	cout<<"\nAverage wait time : "<<(avgWait/n)<<"\nAverage Turn Around Time : "<<(avgTT/n);

	return 0;
}