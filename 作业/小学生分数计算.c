#include<stdio.h>
int max(int x,int y)
{
    return(x>y?x:y);
}
int min(int x,int y)
{
    return(x<y?x:y);
}
int maxgongyue(int x,int y)//求最大公约数的自定义函数
{
    int n,m,r,R;
    n=max(x,y);
    m=min(x,y);
    r=n%m;
    R=n%m;
    while(R!=0)
    {
        r=R;
        R=m%r;
        m=r;
    }
    return m;
}
int main()
{
    int a,b,c,d;
    int fm,fz,o;//fm是分母，fz是分子
    char f;
    while(scanf("%d/%d%c%d/%d",&a,&b,&f,&c,&d)!=EOF)
    {
        int sign=0;
        //printf("%d/%d%c%d/%d",a,b,f,c,d);
        //通分
        fm=b*d;
        if(f == '+')
            fz=a*d+c*b;
        else if(f == '-')
            {fz=a*d-c*b;

                if(fz<0)
                    {fz=-1*fz;sign=1;}
            }
        if(fz == fm)
            printf("1\n");
        else if(fz == 0)
            printf("0\n");
        else
        {
            o=maxgongyue(fz,fm);
            if(o == fm)
                printf("%d\n",fz/fm);
            else if(sign == 0)
            printf("%d/%d\n",fz/o,fm/o);
            else
            printf("-%d/%d\n",fz/o,fm/o);
        }
    }
    return 0;
}
