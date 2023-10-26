#include<stdio.h>
void main()
{
    int i,n,s[1001],f[1001];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&s[i],&f[i]);
    }
    int min=s[0],t=0;
    for(i=0; i<n; i++)
    {
        if(min>s[i])
        {
            t=i;
            min=s[t];
        }
        else if(min==s[i])//此处一定要用else if！！
        {

            if(f[t]>f[i])
                t=i;
                min=s[t];
        }
    }
    printf("%02d %02d\n",s[t],f[t]);
}




















/*
#include<stdio.h>
int mine(int array[1001])
{
    int i,mine=array[0];
    for(i=0;i<1001;i++)
    {
        if(mine<array[i])
            mine=array[i];
    }
    return(array[i]);
}
void main()
{
    int i,j,k,n,m=0,s[1001],f[1001],d[1001];
    scanf("%d",&n);
    for(i=0;i<1001;i++)
    {
        d[i]=25;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&s[i],&f[i]);
    }
    for(i=0;i<n;i++)
    {
        if(s[i]==mine(s))
        {
            k++;
            d[m]=i;
            m++;
        }
    }
    if(k==1)
    {
        printf("%02d %02d\n",s[d[0]],f[d[0]]);
    }
    if(k!=1)
    {
        if(f[d[m]]=mine(f))
            printf("%02d %02d\n",s[d[m]],f[d[m]]);
    }

}

*/









/*
#include<stdio.h>
void main()
{
    int mine(int a[]);
    int n,i,j,k,x=0,min,minf,shi,fen,temp;
    scanf("%d",&n);
    int s[1001],f[1001],b[1001];//s代表时，m代表分
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&s[i],&f[i]);
    }
    for(i=0;i<n;i++)
    {
        if(s[i]=mine[s])
            b[x]=i;
    }
    for(i=0;i<n;i++)
    {
        if(min==s[i])
        {
            minf=f[0];
            for(j=0;j<n;j++)
            {
                if(minf>f[i])
            {fen=i;}
            }
        }
        temp=0;
    }
    if(temp==1)
    printf("%02d %02d",s[shi],f[shi]);
    if(temp==0&&s[fen]==mine(fen))
        printf("%02d %02d",s[fen],f[fen]);


}
int mine(int array[1001])
{
    int i,mine=array[0];
    for(i=0;i<1001;i++)
    {
        if(mine<array[i])
            mine=array[i];
    }
    return(array[i]);
}
*/
