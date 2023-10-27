/*
#include<stdio.h>
#include<string.h>
void main()
{
    char love[1005];
    int two[1005];
    scanf("%s",love);
    getchar();
    for(int i=0; i<strlen(love); i++)
    {
        int sang,beichushu,j;
        for(beichushu=love[i], j=0;;)
        {
            sang=beichushu/2;
            two[j]=beichushu%2;
            j++;
            if(sang==0)
                break;
            if(sang!=0)
                beichushu=sang/2;
        }
        for(j=strlen(two)-1; j>=0; j--)
        {
            printf("%d",two[j]);
        }
        memset(two,0,strlen(two));
        printf("\n");
    }
}*/


#include<stdio.h>
int a[25], i;//由数组a储存2进制结果
void binary_fun(int n)
{
    //二进制不足8位的在前面补0
    if(n<=64)//2的6次方等于64，小于等于64说明最多6位二进制，要补两个0
        printf("00");
    else
        printf("0");//ascall常用码最大为127，2的7次方为128，所以转为二进制再大也达不到八位，至少添加1个0

    i = 0;
    do//用 do-while 防止有n<2的情况
    {
        a[i++] = n % 2;
        n =n/2;
    }while (n);

    while(i--)// 倒序输出
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

void main()
{
    char love[1005];
    gets(love);//C语言接受带空格的字符串
    for(int i=0; i<strlen(love); i++)
    {
        int two=(int)(love[i]);
        binary_fun(two);
    }
}








