///���壡��ָ�룡
/*
#include<stdio.h>
int main()
{
    void inv(int * x,int n);
    int i,arr[10],*p=arr;//arr������������arr��Ԫ�ص�ַ
    for(i=0;i<10;i++,p++)
        scanf("%d",p);
    p=arr;//��ָ���������ָ��arr[0];
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

/*��n��ѧ������Ϣ������ѧ�ţ��������ɼ�����Ҫ��
���ճɼ��ĸߵ�˳�������ѧ������Ϣ��
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
    {10106,"Li",86},{10108,"Ling",73.5},{10110,"Sum",100}};//����ṹ�����鲢��ʼ��
    struct student temp;//����ṹ�����temp����������ʱ����ʱ����
    const int n=5;//���峣����n
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


/*��n���ṹ��������ں�ѧ��ѧ�ţ�������3�ſγ̵ĳɼ���Ҫ�����ƽ���ɼ���ߵ�ѧ������Ϣ(����ѧ�ţ�������3�ſγ̳ɼ���ƽ���ɼ���)
����˼·����n��ѧ�������ݱ�ʾΪ�ṹ�����飨��n��Ԫ�أ������չ��ܺ�������˼�룬�ֱ���3��������ʵ�ֲ�ͬ���ܣ�
��1����input�������������ݺ����ѧ��ƽ���ɼ���
��2����max��������ƽ���ɼ���ߵ�ѧ����
��3����print����������ɼ����ѧ����ȫ����Ϣ��
�����������Ⱥ������3����������ָ��ṹ�������ָ����ʵ�Ρ����õ������
Ϊ�򻯲�����������ֻ��3��ѧ����n=3����
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
