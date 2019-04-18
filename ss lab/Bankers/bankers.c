#include<stdio.h>
#include<stdlib.h>


int avail[1][10];
void print(int x[][10],int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",x[i][j]);
		}
	}
}

//Resource Request algorithm
void res_request(int A[10][10],int N[10][10],int AV[1][10],int W[1][10],int pid,int m)
{
	int reqmat[1][10];
	int i;
	printf("\n Enter additional request :- \n");
	for(i=0;i<m;i++)
          {
		printf(" Request for resource %d : ",i+1);
		scanf("%d",&reqmat[0][i]);
	  }

	for(i=0;i<m;i++)
          {
		if(reqmat[0][i] >= N[pid][i])
                    {
			printf("\n Error encountered.\n");
			exit(0);
	            }
          }

	for(i=0;i<m;i++)
         {
		if(reqmat[0][i] > W[0][i])
                {
			printf("\n Resources unavailable.\n");
			exit(0);
		}
         }


	for(i=0;i<m;i++)
         {
		avail[0][i]-=reqmat[0][i];
		A[pid][i]+=reqmat[0][i];
		N[pid][i]-=reqmat[0][i];
		W[0][i]=avail[0][i];
		AV[0][i]=W[0][i];
	 }
}


//Safety algorithm
int safety(int A[][10],int N[][10],int AV[1][10],int n,int m,int a[],int s[1][10],int W[1][10]){

	int i,j,k,x=0;
	int F[10];
	int pflag=0,flag=0;
	for(i=0;i<n;i++)
		F[i]=0; // not finished
	for(i=0;i<m;i++)
		W[0][i]=AV[0][i]-s[0][i];
	for(i=0;i<m;i++)
	{
		avail[0][i]=W[0][i];
		s[0][i]=0;
	}
	printf("\n\n Available\n");
	for(i=0;i<m;i++)
		printf("\t %d",W[0][i]);

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
        {
			if(F[i] == 0)
			{
				flag=0;//flag=0 when need<work
				for(j=0;j<m;j++)
				{
					if(N[i][j] > W[0][j])
						flag=1;
				}
				if(flag == 0 && F[i] == 0)
				{
					for(j=0;j<m;j++)
						W[0][j]+=A[i][j];
					//printf("\tP%d",i);
					F[i]=1;// finished process i
					pflag++;// no of processes completed
					a[x++]=i;// safe sequence stored in a

				}
			}
		}
		if(pflag == n)// all processes completed safe sequence
			return 1;
	}
	return 0;
}


//Banker's Algorithm
void accept(int A[][10],int N[][10],int M[10][10],int AV[1][10],int *n,int *m,int s[1][10],int W[1][10]){
	int i,j;
	printf("\n Enter total no. of processes : ");
	scanf("%d",n);
	printf("\n Enter total no. of resources : ");
	scanf("%d",m);
	for(i=0;i<*n;i++){
		printf("\n Process %d\n",i+1);
		for(j=0;j<*m;j++){
			printf(" Allocation for resource %d : ",j+1);
			scanf("%d",&A[i][j]);
			printf(" Maximum for resource %d : ",j+1);
			scanf("%d",&M[i][j]);
		}
	}

	for(i=0;i<*m;i++){
		s[0][i]=0;
		for(j=0;j<*n;j++){
			s[0][i]+=A[j][i];
		}
	}

	printf("\n Available resources : \n");
	for(i=0;i<*m;i++){
		printf(" Resource %d : ",i+1);
		scanf("%d",&AV[0][ i]);
	}

	for(i=0; i<*n;i++)
		for(j=0;j<*m;j++)
			N[i][j]=M[i][j]-A[i][j];

	printf("\n Allocation Matrix:");
	print(A,*n,*m);
	printf("\n Maximum Requirement Matrix:");
	print(M,*n,*m);
	printf("\n Need Matrix:");
	print(N,*n,*m);

}

int banker(int A[][10],int N[][10],int AV[1][10],int n,int m,int s[1][10],int W[1][10]){
	int j,i,a[10];// a stores the safety sequence
	j=safety(A,N,AV,n,m,a,s,W);
	if(j != 0 )
    {
		printf("\n\n");
		printf("\n A safety sequence has been detected.\n");
		for(i=0;i<n;i++)
		{
		    printf("\tP%d",a[i]);
		}
		return 1;
	}
	else{
		printf("\n Deadlock has occured.\n");
		return 0;
	}
}


int main(){
	int ret;
	int A[10][10];//allocated
	int M[10][10];//max for each process
	int N[10][10];//need of each
	int AV[1][10];//total max resources
	int W[1][10];//work
	int s[1][10];//some of allocate
	int n,m,pid,ch;
	accept(A,N,M,AV,&n,&m,s,W);
	ret=banker(A,N,AV,n,m,s,W);
	if(ret !=0 ){
		printf("\n Do you want make an additional request ? (1=Yes|0=No)");
		scanf("%d",&ch);
		if(ch == 1){
			printf("\n Enter process number : ");
			scanf("%d",&pid);
			res_request(A,N,AV,W,pid-1,m);
			ret=banker(A,N,AV,n,m,s,W);
			if(ret == 0 )
				exit(0);
		}
	}

	else
		exit(0);
	return 0;
}
