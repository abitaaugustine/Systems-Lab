#include<stdio.h>
int p[10],n,i;
float at[10],bt[10],ct[10],tat[10],wt[10];
void fcfs()
{
	float atat=0,awt=0;
	ct[0]=bt[0];
	for(i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
	for(i=0;i<n;i++)

	{

        tat[i]=ct[i]-at[i];

		wt[i]=tat[i]-bt[i];

	}
	printf("\n\nprocess   arr time   burst time     comp time      wait time         tat");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%f\t%f\t%f\t%f\t%f",p[i],at[i],bt[i],ct[i],wt[i],tat[i]);
	}
	for(i=0;i<n;i++)
	{
		atat+=tat[i];
		awt+=wt[i];
	}
	atat/=n;
	awt/=n;
	printf("\n avg waiting time: %f\n avg turn around time: %f",awt,atat);
}
void enter()
{
    for(i=0;i<n;i++)
	{
		p[i]=i;
		scanf("%f%f",&at[i],&bt[i]);
	}
}
void print()
{
	printf("process   arr time   burst time");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%f\t%f",p[i],at[i],bt[i]);
	}
}
void main()
{
	printf("\n Enter the no.o processes:");
	scanf("%d",&n);
	printf("\n enter the arrival time and burst time:");
	enter();
	print();
	fcfs();
}
