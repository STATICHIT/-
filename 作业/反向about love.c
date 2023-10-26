#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    char a[n][9];
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    for(j=0;j<n;j++)
    {
        int er=0;
        for(i=0;i<8;i++)
        {
            er=er+(a[j][i]-'0')*pow(2,7-i);
        }
        printf("%c",er);//
    }
    printf("\n");
    return 0;
}
