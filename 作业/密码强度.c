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
        int a=0,b=0,c=0,d=0,sum=0;//֮�������ǵĳ�ʼ��Ҫ����whileѭ��������Ϊÿ��ѭ����Ҫ����ʹ����Ϊ0
        gets(mima);
        if(strlen(mima)<8||strlen(mima)>16)
        {
            printf("NO\n");
            continue;//����һ��������continueŶ��������������������ͽ����ˣ�
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
