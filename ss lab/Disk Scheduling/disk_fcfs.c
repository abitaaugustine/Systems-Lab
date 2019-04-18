#include<stdio.h>
#include<math.h>

int q[10],n,h,d,i,s;
float a;

void fcfs()
{
	printf("\n head is %d\nrequests are:",h);
	for(i=0;i<n;i++)
	{
		printf("\t%d",q[i]);
	}
	d=0;
	for(i=0;i<n;i++)
	{
		s=q[i]-h;
		d+=abs(s);
		h=q[i];
	}
	a=(float)d/n;
	printf("\n Distance or tracks travelled = %d \n Avg Distance or tracks travelled = %f",d,a);
}

void main()
{
	printf("\n Enter the no of requests and the initial position of head:");
	scanf("%d%d",&n,&h);
	printf("\n Enter the queue of request:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&q[i]);
	}
	fcfs();
}
