#include<stdio.h>
int p[10],n,i;
float at[10],bt[10],ct[10],tat[10],wt[10];

void sjf()
{
	int s,d,t,j;
	float k,atat=0,awt=0;
	ct[0]=bt[0];
	for(i=1;i<n;i++)
	{
		if(at[i]<=ct[i-1]) // process arrive on or before completion of the one before it
			s=bt[i];
        d=i;
		for(j=i+1;j<n;j++)
		{
			if(s>bt[j] && at[j]<=ct[i-1])
			{
				s=bt[j];
				d=j;
			}
		}
		t=p[i];
		p[i]=p[d];
		p[d]=t;

		k=at[i];
		at[i]=at[d];
		at[d]=k;

		k=bt[i];
		bt[i]=bt[d];
		bt[d]=k;

		ct[i]=ct[i-1]+bt[i];
	}
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	printf("\n\nprocess   arr time   burst time   comp time    wait time      tat");
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
	sjf();
}
