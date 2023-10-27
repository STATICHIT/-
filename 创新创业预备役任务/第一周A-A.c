/*
#include<stdio.h>
struct node
{
    char name[20];
    int age;
    float score;
};
int main()
{
    struct node a;
    scanf("%s%d%f",&a.name,&a.age,&a.score);
    printf("%s %d %f",a.name,a.age,a.score);
}
*/
#include<stdio.h>
#include<string.h>
int sum[5000000];
int main()
{
    int i,j,n,m;
    while(~scanf("%d %d",&n,&m))
    {
        memset(sum,0,5000000);
        int temp=0,a[3010];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)//桶排
            for(j=i+1;j<n;j++)
                sum[a[i]+a[j]]++;

        for(temp=0,i=10000;i>=0&&temp<m;i--)
        {
            if(sum[i]!=0)
                for(j=0;j<sum[i]&&temp<m;j++)///要确保有效终止！！
                {
                    if(temp == m-1)
                    {
                        printf("%d",i);//最后一个数据的后面没用空格
                        temp++;
                    }
                    else if(temp!=m-1)
                    {
                        printf("%d ",i);
                        temp++;
                    }
                    //printf("temp=%d    /// ",temp);///检查temp
                }
        }
        //printf("sdfa");//检查最后一个数字后面是否有多余空格
        printf("\n");
    }
    return 0;
}
///遇到输出超限就是字面问题，输出了多余的东西！！
/*需要输出前m个大的结果，其实可以用m--来控制输出个
数，就不用i<m呀，又temp++记录次数呀，比较呀来计算，
可以简单方便很多！*/
