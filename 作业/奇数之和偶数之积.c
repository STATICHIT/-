//��1��100֮�������֮�ͣ�ż��֮����
#include<stdio.h>
void main()
{
    int i,j,sum=0;
    long long ji=1;
    for(i=1; i<=99; i=i+2)
    {
        sum=sum+i;
    }
    for(j=2; j<=100; j=j+2)
    {
        ji=ji*i;
    }
    printf("1��100֮�������֮��Ϊ%d,ż��֮��Ϊ%d��\n",sum,ji);
}
