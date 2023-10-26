#include<stdio.h>
void main()
{
    int n,i,a,b;
    char x,y,z;
    int add(int a,int b);
    int mul(int a,int b);
    int sub(int a,int b);
    float div(int a,int b);

    while(~scanf("%d",&n))
    {
        getchar();
        for(i=1; i<=n; i++)
        {
            scanf("%c%c%c(%d,%d)",&x,&y,&z,&a,&b);
            getchar();
            switch(x)
            {

            case'a':
                    printf("%d\n",add(a,b));
                break;
            case'm':
                printf("%d\n",mul(a,b));
                break;
            case's':
                printf("%d\n",sub(a,b));
                break;
            case'd':
                    div(a,b);
                break;
            }
        }

    }
}
int add(int a,int b)
{
    return(a+b);
}
int mul(int a,int b)
{
    return(a*b);
}
int sub(int a,int b)
{
    return(a-b);
}
float div(int a,int b)
{
    if(b==0)
    {
        printf("error\n");
    }
    else if(a%b==0)
    {
        printf("%d\n",a/b);
    }
    else if(a%b!=0)
    {
        printf("%.2f\n",a*1.0/b);//除法时分子一定要是小数！！！！a*0.1超级关键
    }
}


//心得：哇太开心了这道题战线差不多三个半小时，做出来真是太太太开心了！！！
///题目：问题 B: 四则运算函数

//  与简单的求和函数类似，但是这次不单单是20以内的求和了。我们定义了四个函数，add(a,b)=a+b; sub(a,b)=a-b; mul(a,b)=a*b; div(a,b)=a/b，输出它们的值。
//a b 都是整数
//格式
//输入格式
//输入数据有多组。
//第一行输入n，接下来n行输入n个函数。（保证是单层运算，不会出现如：add(add(a,b),c)这样的情况）
//输出格式
  //顺序输出对应函数的值。
// 每个输出占一行。
// 除法运算中，除数为0时输出“error”，得到的商不是整数的保留两位小数。
