#include<stdio.h>
#include<string.h>
struct information
{
    char name[100];
    char in[20];
    char out[20];
};
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,i;
        scanf("%d",&m);
        struct information num[100];
        for(i=0;i<m;i++)
        {
            scanf("%s%s%s",num[i].name,num[i].in,num[i].out);
        }
        if(m == 1)
            printf("%s %s\n",num[0].name,num[0].name);
        else if(m>1)
        {
            char early[20],late[20];
            int temp1=0,temp2=0;
            strcpy(early,num[0].in);
            //printf("%s\n",early);//检查early字符数组赋值情况
            for(i=0;i<m;i++)
            {
                if(strcmp(early,num[i].in)>0)
                    {strcpy(early,num[i].in);temp1=i;}
            }
            strcpy(late,num[0].out);
            for(i=0;i<m;i++)
            {
                if(strcmp(late,num[i].out)<0)
                    {strcpy(late,num[i].out);temp2=i;}
            }
            printf("%s %s\n",num[temp1].name,num[temp2].name);
        }
    }
    return 0;
}
