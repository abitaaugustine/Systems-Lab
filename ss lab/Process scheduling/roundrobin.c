#include<stdio.h>
int p[10],n,i,ctt=0;
float at[10],bt[10],ct[10],tat[10],wt[10],q,burst[10],rem=0,r;

void rr()
{
	float atat=0,awt=0;
	for(i=0;i<n;i++)
	{
		rem+=bt[i];
	}
	//printf("\n rem=%f",rem);
	r=rem;
	while(rem>0)
	{
		//printf("\n");
		for(i=0;i<n;i++)
		{
			if(burst[i]>q)
			{
				if(at[i]<=ctt)
				{
					burst[i]-=q;
					rem-=q;
					ctt+=q;
				}
				//printf("\t %d",i);
			}
			else if(burst[i]<=q)
			{
				if(burst[i]!=0 && at[i]<=ctt)
				{
					rem-=burst[i];
					ctt+=burst[i];
					burst[i]=0;
					ct[i]=ctt;  //ctt=r-rem;
				}
			}
			//printf("\t rem=%f",rem);
		}
	}
	for(i=0;i<n;i++)
	{
 		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	printf("\n\nprocess   arr time   burst time        comp time      wait time         tat");
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
		burst[i]=bt[i];
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
	printf("\n enter the quantum time:");
	scanf("%f",&q);
	printf("\n enter the arrival time and burst time:");
	enter();
	print();
	rr();
}

