#include<stdio.h>
void main()
{
    int N,M,i,j,t,sum=0;
    int P[1001],A[2000001];
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d",&P[i],&A[P[i]]);
    }
    for(j=0;j<M-1;j++)
    {
     for(i=0;i<M-1-j;i++)
     {
         t=P[i];
         P[i]=P[i+1];
         P[i+1]=t;
     }
     for(i=0;i<M;i++)
     {
     if(N<=A[P[i]])
     {
         printf("%d\n",N*P[i]);
         break;
     }
     if(N<A[P[])
    }
}
