/*
#include<stdio.h>
#include<string.h>


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
    for(int i=0;i<=5;i++){
        struct node* data = (struct node*)malloc (sizeof(struct node));
        struct SCORE concent ;
        cin>>concent.name>>concent.sco;
        data.scores=concent;
        data.next=NULL;
        head->next=data;
        head= data;
    }

    struct node * pmove=head->next;
    int k=0;
    while(pmove!=NULL){
        cout<<pmove.scores.name<<" "<<pmove.scores.sco<<endl;
        k++;
    }
    cout<<"һ����"<<k<<"������"<<endl;

    return 0;
}
*/

#include<stdio.h>
int main()
{
   long long i,N,a,b,c,d,e,f,m,n,j,k;
   scanf("%d",&N);
   for(N--){
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&f,&e);
    n=a+d;
    k=b+f;
    j=c+e;
    if(j>=60){
        j-=60;
        k++;
    }
    if(k>=60){
        k-=60;
        n++;
    }
    printf("%d %d %d\n",n,k,j);
   }
}

