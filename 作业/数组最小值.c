#include<stdio.h>
int main()
{
    int c[15]={0};
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        c[b]++;
    }
    int min=1;
    for(int i=1;i<=n;i++){
        if(c[min]>c[i]){
            min=i;
        }
    }
    printf("%d\n",min);
    return 0;
}
