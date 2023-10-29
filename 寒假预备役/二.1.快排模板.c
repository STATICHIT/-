#include<stdio.h>
int n,a[100000];
void quicksort(int l,int r)
{
    int i,j,mid,t;
    mid=a[(l+r)/2];//中间数
    i=l;j=r;
    while(i<=j)//中间数并不是中值
    {
        while(a[i]<mid) i++;//遇到大于中间数的值则出
        while(a[j]>mid) j--;//遇到小于中间数的值则出
          if(i<=j)//这个判断不可以省略，因为结果两个while，i和j可能已经不满足i<=j了，但是此时还不会跳出while循环
            {
            t=a[i];a[i]=a[j];a[j]=t;//交换
            i++;j--;
            }
    }
    //出来到这里说明此时i>j
    //数据顺序为l.....j.i.....r或j i l...r或l...r j i
    //递归处理左右两边数据
    if(l<j) quicksort(l,j);
    if(i<r) quicksort(i,r);
}
int main()
{
    scanf("%d",&n);
    //输入序列
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//快排
    //输出序列
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);
}

/*
#include<stdio.h>
int a[1000001],n;//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left,int right)
{
    int i,j,mid,t;
    mid=a[(left+right)/2];//temp中存的就是准基数
    i=left;
    j=right;
    while(i<=j)
    {
        while(a[j]>=mid&&i<j)
            j--;
        while(a[i]<=mid&&i<j)
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;j--;
    }
    //出来到这里说明此时i>j
    //递归处理左右两边数据
    if(left<j)quicksort(left,j);
    if(i<right)quicksort(i,right);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//调用快速排序
    //输出结果
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
*/
/*
#include<stdio.h>
int a[100000],n;//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left,int right)
{
    int i,j,t;
    int mid=a[(left+right)/2];
    i=left;
    j=right;
    while(i<j)
    {
        //顺序很重要，要先从右往左找
        while(a[j]>mid)
            j--;
        while(a[i]<mid)
            i++;
        //交换两个数在数组中的位置
        if(i<j)//当哨兵i和哨兵j没有相遇时
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }

    //递归处理左右两边数据
    if(left<j)quicksort(left,j);
    if(i<right)quicksort(i,right);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//调用快速排序
    //输出结果
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
*/
/*
//啊哈算法上的
#include<stdio.h>
int a[1000001],n;//定义全局变量，这两个变量需要在子函数中使用
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
    return 0;
}
*/
