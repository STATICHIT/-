/*
#include <stdio.h>
void input(int *s, int n)//���뺯��
{   int *m;
    for(m=s; m<s+n; m++)
        scanf("%d",m);
}

void sort(int *s,int n)//������
{   int *i, *j, *min, *max, t;
    for (i=s, min=i; i<s+n; i++)//����Сֵ
        for (j=i+1; j<s+n; j++)
              if(*min>*j)
                 {min=j;}
                 //printf("min=%d\n",*min);
    t=*min, *min=*s, *s=t;//����Сֵ���һ��������
    for (i=s+1, max=i; i<s+n; i++)//�����ֵ
        for (j=i+1; j<s+n; j++)
             if(*max<*j)
                {max=j;}
                //printf("max=%d\n",*max);
    t=*max, *max=*(s+n-1), *(s+n-1)=t;//�����ֵ�����һ��������
}

void print(int *s, int n)//�������
{   int *i;
    for (i=s; i<s+n; i++)
        printf("%d ", *i);
    printf("\n");
}

int main()
{
    int a[10], *p=a;
    input(p, 10);            //�������뺯��
    sort(p, 10);             //����������
    print(p, 10);            //�����������
    return 0;
}
*/



/*
#include<stdio.h>
void scan(int *p,int n)
{
    int *r,i;
    for(r=p;r<p+n;r++)
        scanf("%d",r);
}
void sort(int *p,int n)
{
    int *i,*j,*max,*min,t;
    for(i=p,max=p;i<p+n;i++)
        for(j=i+1;j<p+n-1;j++)
        if(*j>*max)
            max=j;
    t=*max;*max=*(p+n-1);*(p+n-1)=t;
    for(i=p,min=p;i<p+n;i++)
        for(j=i+1;j<p+n-1;j++)
        if(*j<*min)
            min=j;
    t=*min;*min=*p;*p=t;
}
void print(int *p,int n)
{
    int *r,i;
    for(r=p;r<p+n;r++)
        printf("%d ",*r);
    printf("\n");
}
int main()
{
    int a[10],*q;
    q=a;
    scan(q,10);
    sort(q,10);
    print(q,10);
    return 0;
}

*/

/*
///2
//��һ�ַ���������n���ַ���дһ�����������ַ���
//�дӵ�m���ַ���ʼ��ȫ���ַ����Ƴ�Ϊ��һ���ַ�����
#include<stdio.h>
#include<string.h>
void fun(char * q1,char * q2,int x,int y)
{
    char *i,*j;
    i=q1+x;j=q2;
    while(*j!='\0')
    {
        *i=*j;
        i++;
        j++;
    }
    *i='\0';
    for(i=q1;i<q1+x+y;i++)
        printf("%c",*i);
    printf("\n");
}
int main()
{
    char a[100],b[100],*p,*q;
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    gets(a);
    gets(b);
    int l=strlen(b);
    //printf(a);printf("\n");printf(b);printf("\n");
    p=a;q=b;
    fun(p,q,m,l);
    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
void fun(char * p,int n)
{
    int k=0;
    char *r;
    for(r=p;r<p+n;r++)
    {
        if(*(r-1)>='0' && *(r-1)<='9'&&(*r<'0' || *r>'9'))
                {k++;printf("\n");}
        else if(*r>='0' && *r<='9')
        printf("%c",*r);
    }
    printf("��������Ϊ%d\n",k);
}
int main()
{
    char a[1000],*s;
    gets(a);
    int len=strlen(a);
    s=a;
    fun(s,len);
    return 0;
}
*/


#include<stdio.h>
struct students
{
    int num;
    char name[20];
    float q1;
    float q2;
    float q3;
    float aver;
};
//�Զ����������
int fun(struct students a[])
{
    int k=1;
    for(int i=2;i<=10;i++)
    {
        if(a[i].aver>a[k].aver)
        {
            k=i;
        }
    }
    return k;
}
int main()
{
    struct students stu[15];
    for(int i=1; i<=10; i++)
    {
        scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].q1,&stu[i].q2,&stu[i].q3);
        stu[i].aver=(stu[i].q1+stu[i].q2+stu[i].q3)/3;

        printf("��%d��ͬѧ��ƽ����Ϊ%.2f\n",i,stu[i].aver);
    }
    int k=fun(stu);
    printf("��߷�ѧ������Ϊ��\n");
    printf("%d %s %.2f %.2f %.2f %.2f\n",stu[k].num,stu[k].name,stu[k].q1,stu[k].q2,stu[k].q3,stu[k].aver);

}
