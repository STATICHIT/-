
#include <stdio.h>
#define N 150//定义define变量便于修改
int queue[N], head, qtop;//head为队首，qtop为队顶（最新）
int stack[N], stop;//stop为栈顶
char cz[5];//存储push或pop
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
            if(cz[1] == 'u')//如果输入的是push
            {
                scanf("%d", &a);
                queue[qtop++] = a;//入队
                stack[stop++] = a;//入栈
            }
            else if(cz[1] == 'o')//如果输入的是pop
            {
                if(qtop - head == 0) //对应若操作过程中队列已空仍然收到pop，则输出error

                    flagq = 1;//标记
                if(stop == 0) //对应若操作过程中栈已空仍然收到pop，则输出error
                    flags = 1;//标记

                head++;//队首加1（最左边元素出队）
                stop--;//栈顶减一（最右边元素出栈）
                ///注意：开始入队和入栈都是从最右边及进入的
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
            for(i = 0; i < stop; i++)//栈底是固定的哦
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
