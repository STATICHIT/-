#include<stdio.h>
#include<string.h>
char n[100+10];//用字符数组模拟100位的大数
long long int b[9*100+10];
int main()
{
    long long int i,sum=0,k,c;
    while(gets(n)!=NULL)
{
    for(i=0;i<strlen(n);i++)
    {
        sum+=(n[i]-'0');
    }
   // printf("%lld\n",sum);//检查各位数相加所得情况
    i=0,k=0;
    do
    {
        b[i]=sum%10;
       // printf("b[i]=%lld\n",b[i]);//检查各位数字
        sum=sum/10;
       // printf("sum=%lld\n",sum);//检查
        i++;
        k++;
    }while(sum!=0);
    /*for(i=0;i<k;i++)
    {
        printf("%lld ",b[i]);//检查b数组赋值情况
    }
    printf("\n");*/
    for(i=k-1;i>=0;i--)
    {   c=b[i];
        switch(c)
        {
            case(0):printf("zero ");break;
            case(1):printf("one ");break;
            case(2):printf("two ");break;
            case(3):printf("three ");break;
            case(4):printf("four ");break;
            case(5):printf("five ");break;
            case(6):printf("six ");break;
            case(7):printf("seven ");break;
            case(8):printf("eight ");break;
            case(9):printf("nine ");break;
        }
    }
    printf("\n");
}
    return 0;
}
