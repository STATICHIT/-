
#include <stdio.h>
#define N 150//����define���������޸�
int queue[N], head, qtop;//headΪ���ף�qtopΪ�Ӷ������£�
int stack[N], stop;//stopΪջ��
char cz[5];//�洢push��pop
int main()
{
    int m, n, a, i, flags, flagq;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &n);
        flags = 0;
        flagq = 0;
        stop = 0, head = 0;
        qtop = 0;
        while( n--)
        {
            scanf("%s", cz);
            if(cz[1] == 'u')//����������push
            {
                scanf("%d", &a);
                queue[qtop++] = a;//���
                stack[stop++] = a;//��ջ
            }
            else if(cz[1] == 'o')//����������pop
            {
                if(qtop - head == 0) //��Ӧ�����������ж����ѿ���Ȼ�յ�pop�������error

                    flagq = 1;//���
                if(stop == 0) //��Ӧ������������ջ�ѿ���Ȼ�յ�pop�������error
                    flags = 1;//���

                head++;//���׼�1�������Ԫ�س��ӣ�
                stop--;//ջ����һ�����ұ�Ԫ�س�ջ��
                ///ע�⣺��ʼ��Ӻ���ջ���Ǵ����ұ߼������
            }
        }
        if(flagq == 1)
        {
            printf("error\n");
        }
        else
        {
            for(i = head; i < qtop; i++)
                printf("%d ", queue[i]);
            printf("\n");
        }
        if(flags == 1)
        {
            printf("error\n");
        }
        else
        {
            for(i = 0; i < stop; i++)//ջ���ǹ̶���Ŷ
                printf("%d ", stack[i]);
            printf("\n");
        }
    }
    return 0;
}


/*
#include<stdio.h>
#include<string.h>
int data[1000001],b[1000001],c[1000001];
int main()
{
    int i,j,n;
    memset(b,0,1000001);
    memset(c,0,1000001);
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&data[i]);
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            b[data[j]]++;
            if(b[data[j]]>1)break;
            c[i]++;
        }
        memset(b,0,1000001);
    }
    int k=0;
    for(i=0; i<n; i++)
    {
        if(c[i]>c[k])
            k=i;
    }
    printf("%d\n",c[k]);
    return 0;
}
*/
