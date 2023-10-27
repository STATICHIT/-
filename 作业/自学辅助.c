///冲冲冲！！指针！
/*
#include<stdio.h>
int main()
{
    void inv(int * x,int n);
    int i,arr[10],*p=arr;//arr是数组名，即arr首元素地址
    for(i=0;i<10;i++,p++)
        scanf("%d",p);
    p=arr;//让指针变量重新指向arr[0];
    inv(arr,10);
    for(p=arr;p<arr+10;p++)
    {
        printf("%d ",*p);
    }
    printf("\n");
    return 0;
}
void inv(int * x,int n)
{
    int *p,*i,*j,m,temp;
    m=(n-1)/2;
    i=x;j=x+n-1;p=x+m;
    for(;i<=p;i++,j--)
    {
        temp=*i;
        *i=*j;
        *j=temp;
    }
    return;
}
*/

/*有n个学生的信息（包括学号，姓名，成绩），要求
按照成绩的高低顺序输出各学生的信息。
#include<stdio.h>
struct student
{
    int num;
    char name[20];
    float score;
};
int main()
{
    struct student stu[5]={{10101,"Zhang",78},{10103,"Wang",98.5},
    {10106,"Li",86},{10108,"Ling",73.5},{10110,"Sum",100}};//定义结构体数组并初始化
    struct student temp;//定义结构体变量temp，用作交换时的临时变量
    const int n=5;//定义常变量n
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(stu[j].score>stu[i].score)
            {temp=stu[j];stu[j]=stu[i];stu[i]=temp;}
        }
    }
        for(i=0;i<n;i++)
        {
            printf("%6d %8s %6.2f\n",stu[i].num,stu[i].name,stu[i].score);
        }
        printf("\n");
    return 0;
}
*/


/*有n个结构体变量，内含学生学号，姓名和3门课程的成绩。要求输出平均成绩最高的学生的信息(包括学号，姓名，3门课程成绩和平均成绩！)
解题思路：将n个学生的数据表示为结构体数组（有n个元素）。按照功能函数化的思想，分别用3个函数来实现不同功能：
（1）用input函数来输入数据和求各学生平均成绩。
（2）用max函数来找平均成绩最高的学生。
（3）用print函数来输出成绩最高学生的全部信息。
在主函数中先后调用这3个函数，用指向结构体变量的指针作实参。最后得到结果。
为简化操作，本程序只设3个学生（n=3）。
*/
/*
#include<stdio.h>
struct student
{
    int num;
    char name[20];
    float score[3];
    float aver;
};
void input(struct student stu[])
{
    int i;
    for(i=0;i<3;i++)
    {
        scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }
}
struct student max(struct student stu[])
{
    int i,m=0;
    for(i=0;i<3;i++)
        if(stu[i].aver>stu[m].aver)m=i;
        return stu[m];
}
void print(struct student stud)
{
    printf("%d %s %5.1f %5.1f %5.1f %6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}
int main()
{
    struct student stu[3],*p=stu;
    input(p);
    print(max(p));
    return 0;
}
*/

#include<stdio.h>
void sort(int *a,int n)
{
    int *p,*q,*t,temp;
    for(p=a;p<a+n-1;p++)
        for(q=p+1;q<a+n;q++)
            if(*q>*p)
            {temp=*p;*p=*q;*q=temp;}
}
int main()
{
    int i,a[10],*p;
    p=a;
    for(;p<p+9;p++)
    {
        scanf("%d",p);
    }
    p=a;
    sort(p,10);
    for(p=a;p<p+9;p++)
    {
        printf("%d ",*p);
    }
    printf("\n");
    return 0;
}
