/*
#include<stdio.h>
#include<string.h>
int main()
{
    int i,n=0;
    char a[200+10];
    gets(a);
    int l=strlen(a);
    for(i=0; i<l; i++)
    {
        switch(a[i])
        {
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case ' ':n=n+1;break;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x':n=n+2;break;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y':n=n+3;break;
        case 's':
        case 'z':n=n+4;break;
        }
    }
    printf("%d\n",n);
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100+5];
    int i,ans=0,n;
    scanf("%d",&n);
    scanf("%s",a);///这道题就是这个地方一定
                  ///要用%s输入，我也不知道为什么但是
                  ///学长说做洛谷的题目尽量用%s
    //printf(a);//检查字符数组输入情况
    //printf("\n");
    for(i=0; i<strlen(a); i++)
    {
        if(a[i] == 'V'&&a[i+1] == 'K')
        {
            ans++;
            a[i]='a';
            a[i+1]='b';
        }
    }

    for(i=0; i<strlen(a); i++)
    {
        if(a[i] == a[i+1])
        {
            ans++;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    int i,x=0,y=0;
    char a[300];
    scanf("%s",a);
    int l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]=='b'&&a[i+1]=='o'&&a[i+2]=='y'){y++;i+=2;continue;}//发现boy时
		if(a[i]=='b'&&a[i+1]=='o'){y++;i+=1;continue;}//发现bo时
		if(a[i]=='o'&&a[i+1]=='y'){y++;i+=1;continue;}//发现oy时
		if(a[i]=='b'){y++;continue;}//发现b时
		if(a[i]=='o'){y++;continue;}//发现o时
		if(a[i]=='y'){y++;continue;}//发现y时
		if(a[i]=='g'&&a[i+1]=='i'&&a[i+2]=='r'&&a[i+3]=='l'){x++;i+=3;continue;}//发现girl时
		if(a[i]=='g'&&a[i+1]=='i'&&a[i+2]=='r'){x++;i+=2;continue;}//发现gir时
		if(a[i]=='g'&&a[i+1]=='i'){x++;i+=1;continue;}//发现gi时
		if(a[i]=='i'&&a[i+1]=='r'&&a[i+2]=='l'){x++;i+=2;continue;}//发现irl时
		if(a[i]=='r'&&a[i+1]=='l'){x++;i+=1;continue;}//发现rl时
		if(a[i]=='i'&&a[i+1]=='r'){x++;i+=1;continue;}//发现ir时
		if(a[i]=='g'){x++;continue;}//发现g时
		if(a[i]=='r'){x++;continue;}//发现r时
		if(a[i]=='i'){x++;continue;}//发现i时
		if(a[i]=='l'){x++;continue;}//发现l时
    }
    printf("%d\n%d\n",y,x);
    return 0;
}
*/

/*
///洛谷笨小猴
//解题思路：（因为单词长度小于100，所以一个字母最多出现100次,
最大次数与最小次数的差不会大于100）所以先定义一个100以内素数
的数组赋值备用，而字母的出现次数用sum[26]（每个元素初始化为0）
来记录，每个字母用它在字母表中的顺序替代，遍历单词每个字母，
用sum[s[i]-'a']++;达到记录每个字母出现次数的目的，用两个循环
得出出现次数的最大值和最小值，让两者只差ans与isPrime数组中的
每个数去比对，如果这个差是素数就输出对应结果，如果循环完也没
比对上一个素数，则输出另一种对应结果。

*/
/*
#include<stdio.h>
#include<string.h>
int main()
{
    int isPrime[100],i,j,k=0;
    for(i=2; i<100; i++) //给isPrime数组赋值备用
    {
        for(j=2; j<=i; j++)
        {
            if(i%j == 0)
                break;
        }
        if(j == i)
            isPrime[k++]=i;
    }//100内的质数数为k-1个

    //for(i=0;;i++)//检查100以内质数数组赋值情况
    //{
    //    printf("%d ",isPrime[i]);
    //    if(isPrime[i] == 97)//易得100内最大质数为97
    //        break;
    //}

    char s[101];//被判断单词
    int sum[27]= {0}; //数组用于记录第i个字母的个数
    gets(s);
    for(i=0; i<strlen(s); i++)
    {
        sum[s[i]-'a'+1]++;//若s[i]为a，则sum[s[i]-'a'+1]为sum[1]代表第1个字母a出现次数
    }///感觉可以说这里是用到了类似于桶排的思想       此处没用到sum[0]是为了便于理解
    int max=sum[0],min=100;;//初始化max和min
    for(i=0; i<26; i++)
    {
        if(sum[i]>0)
        {
        if(max<sum[i])
            max=sum[i];
        if(min>sum[i])
            min=sum[i];
        }
    }
    //printf("max=%d,min=%d\n",max,min);//检查最大最小次数计算
    int ans=max-min;
    //printf("ans=%d\n",ans);//检查ans计算情况
    for(i=0; i<k-1; i++)
    {
        if(ans == isPrime[i])
        {
            printf("Lucky Word\n%d\n",ans);
            return 0;
        }
    }
    if(i == k-1)
        printf("No Answer\n0\n");
    return 0;
}

*/

/*
#include<stdio.h>
#include<string.h>
#include<math.h>
int l(int n)
{
    int i,l;
    if(n>=0)
    {
        for(i=0;; i++)
        {
            if(n/pow(10,i)<1)
            {
                l=i;
                return(l);
            }
            else if(n/pow(10,i) == 1)
            {
                l=i+1;
                return(l);
            }
        }
    }
    if(n<0)
    {
        n=-1*n;
        for(i=0;; i++)
        {
            if(n/pow(10,i)<1)
            {
                l=i;
                return(l+1);
            }
            else if(n/pow(10,i) == 1)
            {
                l=i+1;
                return(l+1);
            }
        }

    }

}
int main()
{
    int t,k,i,j;
    char s[20];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        //printf(s);检查s数组赋值
        if(s[0] == 'a')
            k=1;//k=1代表加；
        else if(s[0] == 'b')
            k=2;//k=2代表减；
        else if(s[0] == 'c')
            k=3;//k=3代表乘；

        int n1=0,n2=0,l1=0,l2=0;

        //以下操作在整合第一个数
        for(i=0; i<strlen(s); i++)
        {
            if(s[i] == ' '&&s[i-1]>='0'&&s[i-1]<='9')
            {
                for(j=i-1;; j--)
                {
                    if(j == -1||s[j] == ' ')
                    {
                        break;
                    }
                    n1=n1+(s[j]-'0')*pow(10,i-j-1);
                    l1++;
                }
                break;//因为此处是break就不会再执行for中的i++了
            }
        }
        //printf("n1=%d l1=%d ",n1,l1);//检查n1赋值情况

        //以下操作在整合第二个数
        for(j=i+1; j<strlen(s); j++)
        {
            n2=n2+(s[j]-'0')*pow(10,strlen(s)-1-j);
            l2++;
        }
        //printf("n2=%d\n l2=%d \n",n2,l2);//检查n2赋值情况

        if(k == 1)
        {
            printf("%d+%d=%d\n%d\n",n1,n2,n1+n2,l(n1+n2)+l1+l2+2);
        }
        else if(k == 2)
        {
            printf("%d-%d=%d\n%d\n",n1,n2,n1-n2,l(n1-n2)+l1+l2+2);
        }
        else if(k == 3)
        {
            printf("%d*%d=%d\n%d\n",n1,n2,n1*n2,l(n1*n2)+l1+l2+2);
        }
    }
    return 0;
}

*/

/*
//杨辉三角
#include<stdio.h>
int main()
{
    int a[10][10],i,j;
    for(i=0; i<10; i++)
    {
        a[i][0]=1;
        a[i][i]=1;
        if(i>1)
        {
            for(j=1; j<i; j++)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    int i,k=0;
    gets(a);
    gets(b);
    if(strlen(b)>=5)
    {
        for(i=strlen(a); i<strlen(a)+5+1; i++)
        {
            a[i]=b[k++];
        }
        a[i]='\0';
        printf(a);
    }
    if(strlen(b)<5)
    {
        for(i=strlen(a); i<=strlen(a)+strlen(b); i++)
        {
            a[i]=b[k++];
        }
        a[i]='\0';
        printf(a);
    }
}
*/
