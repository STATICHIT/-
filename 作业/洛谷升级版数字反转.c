#include<stdio.h>
#include<string.h>
int main()
{
    int a[10],i;
    printf("%d\n",a);//数组名代表首元素地址
    for(i=0;i<10;i++)
        scanf("%d",a+i);//a+i即代表a[i]的地址
    for(i=0;i<10;i++)
        printf("%d ",*(a+i));//加上星号代表其值
    printf("\n");
    return 0;
}
