#include<stdio.h>
int he(int a)
{
    int v[10001];
    int  j=1,k=1,A=0,i;
    do
    {
        A=a%10;
        a=a/10;
        v[j]=A;
        k++;
        j++;
    }
    while(a!=0);
    for(i=0; i<k-1; i++)
    {
        A=A+v[i];
    }

    return (A);
}

int main()
{
    int n,i,j,t,a[1000],v[1000];
    while(~scanf("%d",&n))
    {
        if(n==0){return 0;}
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            v[i]=he(a[i]);
            //printf("%d ",v[i]);
        }
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(v[i]>v[j])
                {
                    t=v[i];
                    v[i]=v[j];
                    v[j]=t;
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
                else if(v[i]==v[j])
                {
                    if(a[i]>a[j])
                    {
                        t=a[i];
                        a[i]=a[j];
                        a[j]=t;
                    }
                }
            }
        }
        for(i=0; i<n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
