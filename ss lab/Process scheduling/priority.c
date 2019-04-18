#include<stdio.h>
int n,i;

struct proc{
int pty,pr; // pr=process number, pty=priority
float at,bt,ct,tat,wt;
}p[10],t;

void priority()
{
	int s,d,j;

	p[0].ct=p[0].bt;

	float atat=0,awt=0;
	for(i=1;i<n;i++)
	{
		if(p[i].at<=p[i-1].ct) // process arrive on or before completion of the one before it
        s=p[i].pty;
        d=i;
		for(j=i+1;j<n;j++)
		{
			if(s>p[j].pty && p[j].at<=p[i-1].ct)
			{
				s=p[j].pty;
				d=j;
			}
		}
		t=p[i];
		p[i]=p[d];
		p[d]=t;

		p[i].ct=p[i-1].ct+p[i].bt;
	}
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
	printf("\n\nprocess    arr time     burst time     comp time     wait time   tat");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%f\t%f\t%f\t%f\t%f",p[i].pr,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
	}
	for(i=0;i<n;i++)
	{
		atat+=p[i].tat;
		awt+=p[i].wt;
	}
	atat/=n;
	awt/=n;
	printf("\n avg waiting time: %f\n avg turn around time: %f",awt,atat);
}

void enter()
{
	for(i=0;i<n;i++)
	{
		p[i].pr=i;
		scanf("%f%f%d",&p[i].at,&p[i].bt,&p[i].pty);
	}
}

void print()
{
	printf("process		arr time	burst time	pty");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%f\t%f\t%d",p[i].pr,p[i].at,p[i].bt,p[i].pty);
	}
}

void main()
{
	printf("\n Enter the no.o processes:");
	scanf("%d",&n);
	printf("\n enter the arrival time, burst time and priority:");
	enter();
	print();
	priority();
}
