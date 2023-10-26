#include<stdio.h>
int a[1010][1010];//a数组范围为1010*1010，所以要放在主函数外面
int main()
{
    int i,j,m,n,b=0,k[1010]={0};
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++) //输入二维数组
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<m; i++)
    {
        int min=a[i][0],c=0;
        for(j=0; j<n; j++)//找出该行最小
        {
            if(min>a[i][j])
            {
                min=a[i][j];
                c=j;
            }
        }
        int d=1;//行和列容易搞反！！！注意检查！！！！！
        for(j=0; j<m; j++)//判断行最小是不是列最小
        {
            if(min>a[j][c])
            {
                d=0;
                break;
            }
        }
        if(d == 1)
            k[b++]=a[i][c];
            //printf("XX%d ",a[z][c]);//检查k数组赋值情况
    }
    //printf("b==%d\n",b);//检查b的大小
    for(j=0; j<b-1; j++)//排序鞍点
        for(i=0; i<b-1-j; i++)
            if(k[i]>k[i+1])//冒泡排序是相邻元素之间比较哦，不要混淆了
            {
                int t=k[i];
                k[i]=k[i+1];
                k[i+1]=t;
            }
    for(i=0; i<b; i++)
        printf("%d ",k[i]);
    printf("\n");
    return 0;
}
