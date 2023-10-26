 #include<stdio.h>
void main()
{
    int N;
    int jiecheng(int N);//调用时不要忘了加分号
    scanf("%d",&N);
    if(N>0)//防止系统检测负数时出错
        printf("%d",jiecheng(N));
}
int jiecheng(int N)
    {
        int s;
        if(N==0||N==1)
            s=1;
        if(N>1)//此处为递归条件
            s=jiecheng(N-1)*N;//此处表现了递归关系
                    return(s);//将s返回到函数值，
        //主函数中引用得到的就是N的阶乘这个值
    }
