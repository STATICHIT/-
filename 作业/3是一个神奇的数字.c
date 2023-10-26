/*
//时间超限了
#include<stdio.h>
#include<string.h>
int main()
{
    int c[15];
    int t,i,I,j,g,L,R,time,sum,temp;
    scanf("%d",&t);
    while(t--)
    {
        time=0;
        scanf("%d %d",&L,&R);
        for(i=L; i<=R; i++)
        {
            int ii=i,k=0;
            do
            {
                I=ii%10;
                //printf("I==%d\n",I);
                c[k++]=I;
                ii=ii/10;
            }
            while(ii != 0);
            temp=k;
            k=0;
            //for(int s=0;s<temp;s++)//检查
            //{
            //   printf("c[%d]==%d\n",s,c[s]);
            //}
                for(j=0; j<temp; j++)
                {
                    sum=0;
                    int flag=0;
                    for(g=j; g<temp; g++)
                    {
                        sum=sum+c[g];
                        if(sum%3 == 0)
                        {

                            flag=1;
                            break;
                        }
                    }
                    if(flag == 1)
                        {time++;break;}
                }
            memset(c,0,15);
        }
        printf("%d\n",time);
    }

    return 0;
}
*/
///题解：对于前一百的数可以直接用暴力统计，对于100以上的数一定是可以的。
#include<stdio.h>
#include<string.h>
int main()
{
    int c[15];
    int t,i,I,j,g,L,R,time,sum,temp;
    scanf("%d",&t);
    while(t--)
    {
        time=0;
        scanf("%d %d",&L,&R);
        for(i=L; i<=R&&i<100; i++)
        {

            int ii=i,k=0;
            do
            {
                I=ii%10;
                //printf("I==%d\n",I);
                c[k++]=I;
                ii=ii/10;
            }
            while(ii != 0);
            temp=k;
            k=0;

            for(j=0; j<temp; j++)
            {
                sum=0;
                int flag=0;
                for(g=j; g<temp; g++)
                {
                    sum=sum+c[g];
                    if(sum%3 == 0)
                    {

                        flag=1;
                        break;
                    }
                }
                if(flag == 1)
                {
                    time++;
                    break;
                }
            }
            memset(c,0,15);
        }
        if(R>=100&&L<=100)
            {
                time=time+R-100+1;
            }
            if(R>=100&&L>=100)
            {
                time=time+R-L+1;
            }
        printf("%d\n",time);
    }
    return 0;
}
