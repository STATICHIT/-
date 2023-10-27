#include<stdio.h>
void main()
{
int n;
scanf("%d",&n);
long long a[50000+10];
//循环输入初始化数组a
for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
}
//定义前缀和数组
long long sum[50000+10];
sum[0]=0;
for(int i=1;i<=n;i++){//注意此处是从i=1开始循环
        sum[i]=sum[i-1]+a[i-1];
}//其中sum[i]是当前前缀和，sum[i-1]是i-1的前缀和
 //而a[i-1]，之所以要减1，是因为我们从i=1开始循环
 //而数组是从a[0]开始，要i-1才代表对应的数组下标
int q;
scanf("%d",&q);
//q组输入，q逐渐减小，到q等于0时停止从而达到q组循环的目的
while(q--){
    int l,len;
    scanf("%d %d",&l,&len);
    printf("%lld\n",sum[l+len-1]-sum[l-1]);
    //这里是为了求从第l开始len个数的和
    //遇到这种问题直接考虑前缀和哦！！
    }
}
