#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node * next;
};
struct node * creat(int n)//������������������
{
    struct node *head,*p,*q;
    head=(struct node *)malloc(sizeof(struct node));
    head->next=NULL;
    p=head;
    while(n--)
    {
        q=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&q->num);
        q->next=NULL;
        p->next=q;
        p=q;
    }
    return head;
}
void fun(struct node* head,int n)//ɾ����������head�����е�n�����ɾ��
{
    if(n == 1)//�����ɾ����һ�����Ҫ���⿼��
        head->next=head->next->next;
    else
    {
        int i=1;
        struct node *p;
        p=head->next;
        while(i<n-1)
        {
            p=p->next;
            i++;
        }
        p->next=p->next->next;
    }
}
void fun2(struct node *head,int n,int m)//�����������m����head�ĵ�n��λ��
{
    struct node *p,*q,*t;//tΪҪ����Ľ��
    p=head->next;
    int i=1;
    while(i<n-1)//��������ָ��λ��ʱ����
    {
        p=p->next;
        i++;
    }
    q=p->next;//��¼��ǰ����ʱ����һλ�����ڲ���
    t=(struct node*)malloc(sizeof(struct node));//�ȴ����ٲ���
    t->num=m;//�½���е�ֵΪm
    p->next=t;//�õ�ǰ���ָ���½��
    t->next=q;//�½��ָ��ǰ���ԭ������һλ
}
void print(struct node * head,int N,int n)//ѭ�����
{
    int i=1;
    struct node *p,*q;
    p=head->next;
    while(i<N)//�˴����������while��Ҫ��1���Ǽ�1���ֶ�ģ��һ�¹��̺ܺ��жϣ����Ҳ����
    {
        p=p->next;
        i++;
    }//������ָ��λ��ǰ�����
    while(i<n+1)//��ָ��λ�����һֱ���������һ�����
    {
        printf("%d ",p->num);
        p=p->next;
        i++;
    }
    //��ָ���һ����㣬ѭ�����
    p=head->next;
    i=0;
    while(i<N-1)//���δ�������
    {
        printf("%d ",p->num);
        p=p->next;
        i++;
    }
}
int main()
{
    int n,N,m,k,area;
    scanf("%d",&n);
    struct node * list;
    list=creat(n);//��������
    scanf("%d",&area);//ע��˴������areaָ����ɾ����λ�ã�����ɾ��������Ŷ
    if(area!=0)//��ĿҪ������λ��Ϊ0ʱ��������
    {
        fun(list,area);
    }
    scanf("%d %d",&m,&k);
    fun2(list,m,k);//�������
    scanf("%d",&N);
    if(area != 0)//���ǰ��ɾ���������ٲ������ݣ������������Ȳ���
    {
        print(list,N,n);
    }
    else//���ǰ��û��ɾ�������ٲ������ݣ������������ȼ�1
    {
        print(list,N,n+1);
    }
    return 0;
}
