/*
#include<stdio.h>
int pd1(int n)
{
    int i;
    for(i=2;i<n;i++)
        if(n%i == 0)
            break;
    if(i == n)
    return 1;//����1˵��������
    else
        return 0;
}
int pd2(int n)//Ҫ�жϵ���10��100����֪10��100���ǻ᳤��������nΪ��λ��
{
 int shi,ge;
 ge=n%10;
 shi=n/10;
 if(pd1(ge) == 1&&pd1(shi) == 1&&pd1(shi+ge) == 1)
        return 1;
 else
    return 0;
}
int main()
{
    int i;
    for(i=10;i<100;i++)
    {
        if(pd1(i) == 1&&pd2(i) == 1)
            printf("%d",i);
    }
    printf("\n");
    return 0;
}
*/
