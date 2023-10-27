#include<stdio.h>
int a[101],n;//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left,int right)
{
    int i,j,temp,t;
    if(left>right)//结束语句
    return;
    temp=a[left];//temp中存的就是准基数
    i=left;
    j=right;
    while(i!=j)
    {
        //顺序很重要，要先从右往左找
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        //交换两个数在数组中的位置
        if(i<j)//当哨兵i和哨兵j没有相遇时
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //最终将准基数归位
    a[left]=a[i];
    a[i]=temp;

    //递归处理左右两边数据
    quicksort(left,i-1);
    quicksort(i+1,right);
}
int main()
{
    int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//调用快速排序
    //输出结果
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    getchar();getchar();//用来暂停程序以便查看输出的内容

    return 0;
}


/*
#include<stdio.h>
long long int a[100001];
int n;
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
        return;
    i=left;
    j=right;
    temp=a[left];

    while(i!=j)
    {
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);
    quicksort(i+1,right);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    quicksort(1,n);
    for(i=1;i<n;i++)
        printf("%lld ",a[i]);
    printf("%lld\n",a[n]);
    return 0;
}
*/
