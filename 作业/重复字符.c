/*#include<stdio.h>
#include<string.h>
void main()
{
    int i,sign=0;
    char a[10005],m,n;
    scanf("%s",a);
    getchar();

    for(i=0; i<strlen(a); i=i+2)
    {
        m=a[i];
        n=a[i+1];
        if(m==n)
            continue;

        else
            printf("%c\n",a[i]);
            sign=1;
            break;
    }
    if(sign==0)
        printf("-1\n");
}
*///时间超限
#include<stdio.h>
#include<string.h>
void main()
{
    int j,i,d=0,k;
    char a[10000];
    scanf("%s",a);
    for(i=0; i<strlen(a); i++)//i为被判断数
    {

        for(j=0,k=0; j<strlen(a); j++)//for循环后面一定不能加；
        {
            if(j==i)
            continue;
            if(a[i]==a[j])
                k++;
        }
        if(k==0)
        {
            printf("%c",a[i]);
            break;
        }
        if(k>0)
        {
            d++;
            continue;
        }

    }
    if(d==strlen(a))
        printf("-1\n");

}
/*思路：进行一个循环嵌套，即外循环是0~i，作为被判断数。
内循环是0~i但是要剔除i本身，如果循环过程中有与a[i]相同的字符，
说明a[i]不是只出现了一次，进行下一次循环。
如果一轮内循环结束之后没有与之相同的字符，说明它只出现了一次，
则输出a[i],break结束循环；
如果外循环结束了每个数都不止出现一次，则输出-1.*/
