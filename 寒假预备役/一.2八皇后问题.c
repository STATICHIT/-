#include<stdio.h>
int n,sum=0;//全局变量未初始化时默认为0
///不能全局定义col（开始被这个错误卡了好久）
int a[100],b[100],c[100],d[100];
///之所以不设置为13是因为对角线数远大于N，干脆都开大一些
void dfs(int row)
{
    if(row==n+1)//如果遍历到了第n+1行，则说明已经出了一组结果
    {
        if(sum<3)
        {
            for(int g=1; g<=n; g++)
            {
                printf("%d ",a[g]);
            }
            printf("\n");
        }
        sum++;
        return;
    }
    for(int col=1; col<=n; col++)//每一行从第一个位置开始遍历尝试
    {
        if((b[col] == 0)&&(c[row+col] == 0)&&(d[row-col+n] == 0))
        {
            a[row]=col;//记录皇后位置
            b[col]=1;
            c[row+col]=1;//这里
            d[row-col+n]=1;//和这里 就是标记了当前皇后所在位置的对角线被标记了
            //其中\对角线的表示之所以要加个n是yw有些情况row-col为负数，但数组下标不能为负数，所以这里整体右移n个单位使\对角线数组的下标为正
            dfs(++row);//进一步搜索!
            row--;
            ///这里不能用row++！！！！！！！
            b[col]=0;
            c[row+col]=0;
            d[row-col+n]=0;//这三行是在回溯
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    printf("%d",sum);
    return 0;
}
