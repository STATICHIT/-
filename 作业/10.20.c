#include<stdio.h>
#include<math.h>
#include<string.h>
int a,b,n;
int add(int a,int b)
{
    return a+b;
}

int main()
{
    float f;
    scanf("%f",&f);
    printf("%d",(int)(f=f+1,f=f+1));
    return 0;
}
