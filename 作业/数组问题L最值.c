#include<stdio.h>
void main()
{
    int a[15],max=0,min=0;
    int i,j,n,t,k;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(j=0; j<n; j++)
    {
        if(a[max]<a[j])
            max=j;
        if(a[min]>a[j])
            min=j;
    }
    if(a[0]==a[max]&&a[n-1]==a[min])//之所以要加上这一部分
      {t=a[0];                      //是因为如果最大值恰好是第一个数，最小值恰好是最后一个
    a[0]=a[min];                    //那么只需要交换一次就好了
    a[min]=t;}                      //否则负负得正，结果不会改变，比如 在测试值为5，4，3，2，1时就会出错
    else
    {t=a[0];
    a[0]=a[min];
    a[min]=t;
    k=a[n-1];
    a[n-1]=a[max];
    a[max]=k;}
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
