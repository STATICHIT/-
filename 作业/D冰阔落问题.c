#include<stdio.h>
int main()
{
    int t,ans,i=1,x,y,z;
    scanf("%d",&t);
    while(i<=t)
    {
        scanf("%d %d",&x,&y);
        ans=x/y;
        z=x/y;//z为瓶子数变量//
        while(z>=3)
    {
        ans=ans+z/3;
        z=z/3+z%3;
    }
    i++;
    printf("%d\n",ans);
    }

     return 0;
}

//换出来的瓶子喝完又是空瓶子//
//打草稿很重要！！！把实际问题转化为数学问题！！//

