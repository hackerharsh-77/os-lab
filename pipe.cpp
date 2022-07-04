#include<iostream>
using namespace std;

//waiting time
void findWT(int processes[],int n, int bt[], int wt[], int quantum){
	int rem_bt[n];
	for(int i=0;i<n;i++)
		rem_bt[i]=bt[i];

	int t=0;
	while(1){
		bool done =true;
		for(int i=0;i<n;i++){
			if(rem_bt[i]>0){
				done = false;
				if(rem_bt[i]>quantum){
					t+=quantum;
					rem_bt[i]-=quantum;
				}
				else{
					t+=rem_bt[i];
					wt[i]=t-bt[i];
					rem_bt[i]=0;
				}
			}
		}
	if(done==true)
		break;
	}
}




//TAT
void findTAT(int processes[], int n, int bt[],int wt[],int tat[]){
	for(int i=0;i<n;i++)
		tat[i]=wt[i]+bt[i];
} 


//average
void avgTime(int processes[],int n,int bt[],int quantum){
	int wt[n],tat[n],twt=0,ttat=0;
	findWT(processes,n,bt,wt,quantum);
	findTAT(processes,n,bt,wt,tat);
	cout<<"Processes"<<"Burst Time"<<"waiting Time"<<"Turn Around Time"<<endl;
	
	for(int i=0;i<n;i++){
		twt+=wt[i];
		ttat+=tat[i];
		cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
}


//driven code

int  main(){
	int processes[]={1,2,3};
	int n = sizeof processes/ sizeof processes[0];
	int burst_time[] = {10,5,8};
	int quantum =2;
	avgTime(processes,n,burst_time,quantum);
	return 0;
} 

