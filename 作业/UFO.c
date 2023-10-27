#include<stdio.h>
#include<string.h>
void main()
{
    char n1[7],n2[7];
    int a=1,b=1,i,A,B;
    gets(n1);
    gets(n2);
    for(i=0;i<strlen(n1);i++)
    {
        a*=(n1[i]-64);
    }
    for(i=0;i<strlen(n2);i++)
    {
        b*=(n2[i]-64);
    }
    if((a%47)==(b%47))
        printf("GO\n");
    else
        printf("STAY\n");

}
///mod n就是对结果除n取余
///比如某个数mod3就是它除以3取余的结果
