#include<stdio.h>
#include<string.h>
int main()
{
    int a[10],i;
    printf("%d\n",a);//������������Ԫ�ص�ַ
    for(i=0;i<10;i++)
        scanf("%d",a+i);//a+i������a[i]�ĵ�ַ
    for(i=0;i<10;i++)
        printf("%d ",*(a+i));//�����ǺŴ�����ֵ
    printf("\n");
    return 0;
}
