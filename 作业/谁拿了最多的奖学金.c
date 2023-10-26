#include<stdio.h>
int main()
{
    char s[100][21];
    int n;
    while(~scanf("%d",&n))
    {
        getchar();
        int a[n],b[n],e[n],i,j,aw[n];
        for(j=0; j<n; j++)
        {
            aw[j]=0;
        }
        char c[n+1],d[n+1];
        for(i=0; i<n; i++)
        {
            scanf("%s",s[i]);
            getchar();
            //printf("%s",s[i]);//¼ì²é
            scanf("%d %d",&a[i],&b[i]);
            getchar();
            scanf("%c",&c[i]);
            getchar();
            scanf("%c",&d[i]);
            getchar();
            scanf("%d",&e[i]);
            if(a[i]>80&&e[i]>=1)
            {
                aw[i]+=8000;
            }
            if(a[i]>85&&b[i]>80)
            {
                aw[i]+=4000;
            }
            if(a[i]>90)
            {
                aw[i]+=2000;
            }
            if(a[i]>85&&d[i] == 'Y')
            {
                aw[i]+=1000;
            }
            if(b[i]>80&&c[i] == 'Y')
            {
                aw[i]+=850;
            }
        }
        int sum=0;
        for(i=0; i<n; i++)
        {
            sum+=aw[i];
        }
        int max=0,t;
        for(j=0; j<n; j++)
        {
            if(max<aw[j])
            {
                max=aw[j];
                t=j;
            }
        }
        printf("%s\n%d\n%d\n",s[t],max,sum);
    }
    return 0;
}
