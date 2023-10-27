#include<stdio.h>
struct queue
{
    int data[500];
    int head;
    int tail;
};
struct queue q;
char cz[10];
int main()
{
    int t,x;
    while(~scanf("%d",&t))
    {
        q.head=1;
        q.tail=1;
        while(t--)
        {
            scanf("%s",cz);
            //printf(cz);
            if(cz[0] == 'e')
            {
                scanf("%d",&x);
                q.data[q.tail]=x;
                q.tail++;
            }
            else if(cz[0] == 'd')
            {
                if(q.head<q.tail)
                {
                    printf("%d\n",q.data[q.head]);
                    q.head++;
                }
                else
                    printf("this is empty!\n");
            }
            else if(cz[0] == 'q')
            {
                if(q.head>=q.tail)
                    printf("this is empty!\n");
                else
                {
                    while(q.head<q.tail)
                    {
                        printf("%d\n",q.data[q.head]);
                        q.head++;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
