#include<stdio.h>
#include<string.h>
int main()
{
    char a[52];
    int n,i,l;
    scanf("%d",&n);
    scanf("%s",a);
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]<=('z'-n))
            {a[i]=a[i]+n;}
        else if(a[i]>('z'-n)&&a[i]<='z')
            {a[i]=a[i]+n-26;}
    }

    printf(a);
    return 0;
}
/*核心代码部分可以更加简洁无需if判断
即
for(i=0;i<l;i++)
    {
    a[i]=(a[i]-'a'+n)%26+'a';
    }
就是看a[i]是第26个字母中的第几个.*/
