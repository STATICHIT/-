#include<bits/stdc++.h>
using namespace std;
int n,k,flag,a[101];
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        flag=1;
        scanf("%d",&k);
        for(int i=0; i<k; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+k);
        for(int i=1; i<k; i++)
        {
            if(a[i]==a[i-1])
            {
                flag=-1;
                break;
            }
        }
        if(flag==-1)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
