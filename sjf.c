#include <stdio.h>

void main(){
   int bt[50],wt[50],tat[50],process[20];
	int i,j,a,b,p,temp;
	float wtavg,tatavg;
	printf("Enter the number of processes:");
	scanf("%d",&p);
	wt[0]=0;
	for(i=0;i<p;i++){
		printf("Enter burst time of process %d :",i+1);
		scanf("%d",&bt[i]);
		process[i]=i+1;
		}
		
	for(i=0;i<p;i++){
		for(j=0;j<p-i-1;j++){	
			if( bt[j]>bt[j+1]){
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp=process[i];
				process[i]=process[j+1];
				process[j+1]=temp;
				}	
			}		
		}
		
	for(i=1;i<p;i++){
		wt[i]=wt[i-1]+bt[i-1];
 		tat[i]=bt[i]+tat[i-1];
 		wtavg = wtavg + wt[i];
 		tatavg = tatavg + tat[i];
 		}
 		
 		
  printf("\nPNO.\t BT\t WT\t TAT\n");		
	for(int i=0;i<p;i++){
 		printf("%d\t %d\t %d\t %d\t \n" ,process[i],bt[i],wt[i],tat[i]);
 		}
 		printf("AVG WT:%f\n",wtavg/p);
 		printf("AVG TA:%f\n",tatavg/p);
	
}
