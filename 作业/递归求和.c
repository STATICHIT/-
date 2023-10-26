#include<stdio.h>
void main()
{
    long long int N,j,S=0;
    long long int jiecheng(int i);///这是声明
    scanf("%d",&N);
        for(j=1; j<=N; j++)
        {
            S=S+jiecheng(j);       ///声明和定义要保持一致
        }                          ///但如果自定义在main函数之前，就不用再次声明！
    printf("%lld",S);
}
  long long int jiecheng(int i)///这是定义
{
    long long int s;
    if(i==1)
        s=1;
    if(i>1)
        s=jiecheng(i-1)*i;
    return(s);
}
//做出来了，但没完全做出来emmm
/*#include<stdio.h>
void main()
{
    long long int N,j,S=0,k=1;
    int jiecheng(int i);
    scanf("%d",&N);
        for(j=1; j<=N; j++)
        {
            k=k*j;
            S=S+k;
        }
    printf("%lld",S);
}
*/
