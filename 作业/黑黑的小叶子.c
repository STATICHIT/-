#include<stdio.h>
#include<math.h>
void main()
{
    int n,m,i;
    float v,N;
    scanf("%d\n",&n);
    scanf("%d %f",&m,&v);
    for(i=1; i<=m; i++)
    {
        N=n*pow(1.0-v,m);
    }
    printf("%.1f\n",N);

}
