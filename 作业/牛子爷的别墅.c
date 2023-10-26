#include <stdio.h>
int a[1000001],b[1001]={0};
void main()
{
   int n,k,K=0,i;
   scanf("%d %d",&n,&k);
   for(i=0;i<n;i++){
   scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++){
   b[a[i]]++;
   }
   for(i=1000;i>0;i--){
        if(b[i]!=0){
           printf("%d ",i);
           K++;
        }
        if(K==k)
            break;
   }
   printf("\n");
}
///利用了桶排的思想
//桶排：去重并排序
