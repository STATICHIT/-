#include<bits/stdc++.h>
using namespace std;

struct SCORE //���а����ݽṹ
{
    char name[1000];
    int sco;
} score[1000000]; //�����Դ���1000000����������


struct node//����ṹ
{
    struct SCORE scores;
    struct node* next;
};

void UP_SORT(struct node* head)//���������������
{
    struct SCORE temp;
    struct node* i, * j;
    for (i = head->next; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (j->scores.sco < i->scores.sco)
            {
                temp = j->scores;
                j->scores = i->scores;
                i->scores = temp;
            }
        }
    }
}

int main()
{

    struct node * head = (struct node* )malloc(sizeof(struct node)*1000);
    struct node * p =head;
    for(int i=0;i<3;i++){
        struct node* data = (struct node*)malloc (sizeof(struct node));
        struct SCORE concent ;
        cin>>concent.name>>concent.sco;
        data->scores=concent;
        data->next=NULL;
        p->next=data;
        p= data;
    }

    UP_SORT(head);

    struct node * pmove=head->next;
    int k=0;

    while(pmove!=NULL){
        cout<<pmove->scores.name<<" "<<pmove->scores.sco<<endl;
        k++;
        pmove=pmove->next;
    }
    cout<<"һ����"<<k<<"������"<<endl;

    return 0;
}
