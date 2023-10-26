#include<stdio.h>
int isLeap(int N)
{
    if(N%4!=0)
        return(0);
    else if(N%4==0&&N%100!=0)
        return(1);
    else if(N%400==0)
        return(1);
    else
        return(0);

}

int main()
{
    int t,y,N,i,j;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        int k=0;
        scanf("%d %d",&y,&N);
        for(i=y;; i++)
        {
            if(isLeap(i))
            {
                k++;
                if(k==N)
                    {printf("%d\n",i);
                    break;}
            }
        }
    }
    return 0;
}
