#include<stdio.h>
int main()
{
    long long int a;
    scanf("%lld",&a);
    while(a % 2 == 0)
    {a = a / 2;}
    while(a % 3 == 0)
    {a = a / 3;}
    while(a % 5 == 0)
    {a = a / 5;}
    if(a == 1)
        printf("YES\n");
    else
    printf("NO\n");
    return 0;
}
