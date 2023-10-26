 #include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])//若第i个元素大于i-1元素则直接插入；
                      //反之，需要找到适当的位置再插入
        {j=i-1;
        int x=a[i];
        while(j>=0&&x<a[j])//采用顺序查找方式找到插入的位置
        {                  //在查找的同时，将数组中的元素进
            a[j+1]=a[j];   //行后移操作，给插入元素腾出空间
            j--;
        }
        a[j+1]=x;//插入到正确位置
        }
    }
    for(i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    }
    return 0;
}
