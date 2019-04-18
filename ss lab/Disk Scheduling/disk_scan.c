#include<stdio.h>
#include<math.h>

int q[10],n,h,d,i,s,k,l,t,tq,x,y;
float a;
void scan()
{
	printf("\n head is %d\nrequests are:",h);
	for(i=0;i<n;i++)
	{
		printf("\t%d",q[i]);
	}
	d=0;
	printf("\n Sorting");
	for(i=0;i<n-1;i++)
	{
		l=q[i];
		t=i;
		for(k=i+1;k<n;k++)
		{
			if(q[k]<l)
			{
				l=q[k];
				t=k;
			}
		}
		tq=q[i];.
		q[i]=q[t];
		q[t]=tq;
	}
	for(i=0;i<n;i++)
	{
		if(q[i]<=h)
			k=i;
	}
	printf("\n\n k=%d\nsorted requests are:",k+1);
	for(i=0;i<n;i++)
	{
		printf("\t%d",q[i]);
	}
	d=0;
	printf("\n");
		for(i=k;i>=0;i--)
		{
			printf("\t %d",q[i]);
			s=q[i]-h;
			d+=abs(s);
			h=q[i];
		}
		s=0-h;
		d+=abs(s);
		h=0;
		printf("\t 0");
		//printf("d=%d\t q[i]=%d,h=%d,k=%d",d,q[0],h,k);
		for(i=k+1;i<n;i++)
		{
			printf("\t %d",q[i]);
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
	scan();
}
