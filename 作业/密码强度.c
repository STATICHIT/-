#include<stdio.h>
#include<string.h>
void main()
{
    int M,i,j;
    char mima[55];
    scanf("%d",&M);
    getchar();
    for(i=0;i<M;i++)
    {
        int a=0,b=0,c=0,d=0,sum=0;//之所以他们的初始化要放在while循环内是因为每次循环都要重新使他们为0
        gets(mima);
        if(strlen(mima)<8||strlen(mima)>16)
        {
            printf("NO\n");
            continue;//这里一定不能用continue哦，否则遇到这个情况程序就结束了！
        }
        for(j=0;j<strlen(mima);j++)
        {
            if(mima[j]>='a'&&mima[j]<='z')
                a=1;
            if(mima[j]>='A'&&mima[j]<='Z')
                b=1;
            if(mima[j]>='0'&&mima[j]<='9')
                c=1;
            if(mima[j]=='~'||mima[j]=='!'||mima[j]=='@'||mima[j]=='#'||mima[j]=='$'||mima[j]=='%'||mima[j]=='^'||mima[i]=='&')
                d=1;
        }
        sum=a+b+c+d;
        if(sum>=3)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
