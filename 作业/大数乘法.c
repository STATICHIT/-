#include<stdio.h>
#include<string.h>
int main()
{
 char a[100],b[100];//用字符串输入数字
 int x[101],y[101],z[202]={0};

    int la,lb,i,j;
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    la=strlen(a);lb=strlen(b);
    for(j=0,i=la-1;i>=0;i--)//转数字并倒序
    {
        x[j++]=a[i]-'0';
    }
    for(j=0,i=lb-1;i>=0;i--)
    {
        y[j++]=b[i]-'0';
    }
    for(i=0;i<la;i++)
    {
        for(j=0;j<lb;j++)
        {
            z[i+j]=z[i+j]+x[i]*y[j];//先乘不进位
        }
    }
    for(i=0;i<202;i++)//进位
    {
        if(z[i]>=10)//如果该位置不是个位数
        {
            z[i+1]=z[i+1]+z[i]/10;//将上一位的十位数加过来
            z[i]=z[i]%10;//将上一位的各位数字保留给它自己
        }
    }
    for(i=201;i>0;i--)//删除前导0
    {
        if(z[i] == 0)
        continue;
        else
        break;
    }//这里结束后i为不为第一个0的数的下标
    for(;i>=0;i--)//倒叙输出
    {
        printf("%d",z[i]);
    }
    printf("\n");
    return 0;
}
