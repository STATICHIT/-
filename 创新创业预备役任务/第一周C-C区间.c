///C-C.
#include<stdio.h>
struct tv
{
    int begin;
    int finish;
};
int main()
{
    int n,i,j,k,sign;
    while(~scanf("%d",&n)&&n)//n=0表示输入结束，不做处理.
    {
        struct tv a[110],temp;
        for(i=0; i<n; i++)
            scanf("%d %d",&a[i].begin,&a[i].finish);
        for(i=0; i<n-1; i++)//按照结束时间由早到晚排序
        {
            for(j=i+1; j<n; j++)
            {
                if(a[j].finish<a[i].finish)
                {
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
            }
        }
        //检查按照结束时间排序的结果
        /*for(i=0;i<n;i++)
        {
            printf("%d %d\n",a[i].begin,a[i].finish);
        }*/
        //printf("----分界线----");//
        int k=a[0].finish,time=1;
        for(i=1; i<n; i++)
        {
            if(a[i].begin>=k)
            {
                time++;
                k=a[i].finish;
                //printf("time==%d,k==%d\n",time,k);///检查time和k1
            }
        }
        printf("%d\n",time);
    }
    return 0;
}
///这道题的思路就是：先把结构体类型数据按照结束时间排序
///为使得看完更多节目，结束时间越早越好，每次选择开始时
///间比上一个结束时间晚但结束时间相对最早的节目。
