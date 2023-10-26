#include<stdio.h>
struct money//用结构体储存每堆金币信息
{
    double m;//重量
    double v;//价值
    double x;//性价比
};
int main()
{
    int n,i,j;
    double t;
    scanf("%d %lf",&n,&t);
    struct money a[101],temp;
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf",&a[i].m,&a[i].v);
        a[i].x=a[i].v/a[i].m;//每次输入金币信息就立刻求出这一堆的性价比
    }
    for(j=0; j<n-1; j++)//因为是c语言，所以要手动排序！也可以打包为一个函数丢到外面
    {
        for(i=0; i<n-1-j; i++)
        {
            if(a[i].x<a[i+1].x)
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    /*
    for(i=0; i<n; i++)//检查排序操作是否正确
        printf("%d  %d  %f   \n",a[i].m,a[i].v,a[i].x);
    */
    double s=0,sum=0;
    for(i=0; i<n; i++)
    {
        s+=a[i].m;
        if(t>=s)//容量够全拿
        {
            sum+=a[i].v;
        }
        else if(t<s)//容量不够装满
        {
            sum+=(t-s+a[i].m)*a[i].x;//注意这里是和a[i].x相乘（它是浮点型）
            break;                  //为了防止类型转换出错，可以把所有相关数据改成浮点型
        }
    }
    printf("%.2lf",sum);
    return 0;
}
