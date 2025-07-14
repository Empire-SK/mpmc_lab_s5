#include <stdio.h>

void main(){
   int bt[50],wt[50],tat[50];
	int i,j,a,b,p;
	float avg_wt,avg_turn;
	printf("Enter the number of processes:");
	scanf("%d",&p);
	wt[0]=0;
	for(i=0;i<p;i++){
		printf("Enter burst time of process %d :",i+1);
		scanf("%d",&bt[i]);
		}
	for(i=0;i<p;i++){
		wt[i+1]=wt[i]+bt[i];
		avg_wt = avg_wt + wt[i]; 
	}
	for(int i=0;i<p;i++){
 		tat[i]=bt[i]+wt[i];
 		avg_turn = avg_turn + tat[i]; 
 		}
         
 		
 		
  printf("PNO.\t BT\t WT\t TAT\n");		
	for(int i=0;i<p;i++){
 		printf("%d\t %d\t %d\t %d\t \n" ,i+1,bt[i],wt[i],tat[i]);
 		}
 		printf("AVG WT:%f\n",avg_wt/p);
 		printf("AVG TA:%f\n",avg_turn/p);
 		
 		}

