#include<stdio.h>
void main()
{
    long long int n,i,j;
    int digui(long long int n);
    while(~scanf("%lld",&n))
        for(i=1; i<=2*n; i++)
        {
            for(j=0; j<i; j++)
            {
                printf("%lld ",digui(j));//�������Զ��庯��


            }
            printf("\n");
            i++;
        }
}
int digui(long long int n)
{
    if(n==0)
    {
        return(0);
    }
    if(n==1||n==2)
    {
        return 1;
    }
    else
    {
        return(digui(n-1)+digui(n-2));
    }//�ݹ�Ҫ�����Զ��庯���
}
/*���� I: 쳲���������
����
��дһ����쳲��������еĵݹ麯��������nֵ��ʹ�øõݹ麯������������������쳲��������С�

��ʽ
�����ʽ
һ��������n

�����ʽ
��Ŀ�����ж��鲻ͬ�Ĳ������ݣ�����ÿ���������ݣ�
����Ŀ��Ҫ�������Ӧ��쳲�����ͼ�Ρ�

����
�������� Copy
6
������� Copy
0
0 1 1
0 1 1 2 3
0 1 1 2 3 5 8
0 1 1 2 3 5 8 13 21
0 1 1 2 3 5 8 13 21 34 55
��ʾ
���ݵ����ֵ���ᳬ��long long�ķ�Χ*/
