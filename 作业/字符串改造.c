#include<stdio.h>
#include<string.h>
void main()
{
    char a[15+1];
    char ji[15];
    char ou[15];
    int sign[15+1]={0};//偶数标记为0
    int i,j,t;
    gets(a);
    for(i=0;i<=strlen(a)+1;i=i+2)//奇数标记为1
    {
        sign[i]=1;
    }
    /*for(i=0;i<=strlen(a)+1;i++)
    {
    printf("%d ",sign[i]);
    }*///检查sign数组
    for(i=0,j=0;i<=strlen(a)+1;i++)
    {if(sign[i])
    {
            ji[j++]=a[i];
    }
    }
    ji[j]='\0';///单个为字符数组赋值时要把末位赋为'\0'
    /*printf(ji);*///检查ji数组
    for(j=0;j<strlen(ji)-1;j++)
    {
        for(i=0;i<strlen(ji)-1-j;i++)
        {
            if(ji[i]>ji[i+1])
            {t=ji[i];ji[i]=ji[i+1];ji[i+1]=t;}
        }
    }
    //奇数处理完毕
    /*printf(ji);*///检查ji数组顺序
    for(i=0,j=0;i<=strlen(a);i++)
//定义偶数数组时忘记使j=0而卡了很久的bug！！
    {if(sign[i]==0)
    {
        ou[j++]=a[i];
    }
    }
    ou[j]='\0';///单个为字符数组赋值时要把末位赋为'\0'
    /*printf(ou);*///检查ou数组
    for(j=0;j<strlen(ou)-1;j++)
    {
        for(i=0;i<strlen(ou)-1-j;i++)
        {
            if(ou[i]<ou[i+1])
            {t=ou[i];ou[i]=ou[i+1];ou[i+1]=t;}
        }
    }
    //偶数处理完毕
    /*printf(ou);*///检查ou数组顺序
    printf(strcat(ji,ou));
}
