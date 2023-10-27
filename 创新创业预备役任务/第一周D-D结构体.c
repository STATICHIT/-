#include<stdio.h>
#include<string.h>
struct student
{
    char name[20];
    float score;
};
int main()
{
    struct student stu[20];
    struct student temp;
    int i,j,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%s %f",stu[i].name,&stu[i].score);
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(stu[j].score>stu[i].score)
            {temp=stu[j];stu[j]=stu[i];stu[i]=temp;}
            else if(stu[j].score == stu[i].score)
            {
                if(strcmp(stu[j].name,stu[i].name)<0)
                {temp=stu[j];stu[j]=stu[i];stu[i]=temp;}
            }
        }
    }
    for(i=0; i<n; i++)
        printf("%s %.0f\n",stu[i].name,stu[i].score);
    printf("\n");
    return 0;
}
