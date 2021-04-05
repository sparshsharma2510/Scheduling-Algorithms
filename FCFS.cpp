#include <iostream>

using namespace std;

int main(){
	int burst[50],arrive[50],wait[50],turn[50];
	int prog;
	float avgWaitTime = 0, avgTurnAroundTime = 0;
	cout<<"Enter the number of Programs : ";
	cin>>prog;
	for(int i = 0; i < prog; i++){
		cout<<"\nEnter the arrival time for process "<<i+1<<" : ";
		cin>>arrive[i];
	}
	for(int i = 0; i < prog; i++){
		cout<<"\nEnter the burst time for process "<<i+1<<" : ";
		cin>>burst[i];
	}
	wait[0] = 0;
	for(int i = 1; i < prog; i++){
		wait[i] = wait[i-1] + burst[i-1] - (arrive[i]-arrive[i-1]);
		if (wait[i] < 0)
			wait[i] = 0;
	}
	for(int i = 0; i < prog; i++){
		turn[i] = wait[i] + burst[i];
		avgWaitTime += wait[i];
		avgTurnAroundTime += turn[i];
	}
	cout<<"\nProgram No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time"<<endl;
	for(int i = 0; i < prog; i++){
		cout<<i+1<<"\t\t"<<arrive[i]<<"\t\t"<<burst[i]<<"\t\t"<<wait[i]<<"\t\t"<<turn[i]<<endl;
	}
	cout<<"\n Average Wait Time is : "<<avgWaitTime/prog;
	cout<<"\n Average Turn Around Time is : "<<avgTurnAroundTime/prog;
	return 0;
}