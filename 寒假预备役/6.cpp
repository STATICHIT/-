/*
#include<bits/stdc++.h>
using namespace std;

int anst = 0,ansh = 0;
struct abc{
    char vexs[100];
    int mats[100][100];
    int vex,side;
}graph;

int loc(char a){
    for(int i=0;i<graph.vex;i++){
        if(graph.vexs[i] == a){
            return i;
        }
        return -1;
    }
}

void creat(){
    int a1,a2;
    cout<<"����������ͼ��������";cin>>graph.vex;
    cout<<endl<<"����������ͼ������";cin>>graph.side;
    cout<<endl<<"����������ͼ�ĸ����������ƣ� ";
    for(int i=0;i<graph.vex;i++)cin>>graph.vexs[i];
    for(int i=0;i<100;i++){
        for(int j=0;i<100;j++){
            graph.mats[i][j]=0;//��ʼ��
        }
    }
    for(int i=0;i<graph.side;i++){
        printf("��һ�������%d������ߵ���㣬�յ㣺",i+1);getchar();
        cin>>a1>>a2;
        graph.mats[loc(a1)][loc(a2)]=1;
    }
}

void output(){
    for(int i=0;i<graph.vex;i++){
        for(int j=0;j<graph.vex;j++){
            cout<<graph.mats[i][j]<<" ";
        }
        cout<<endl;
    }
}

void count(struct abc *t){
    struct abc s = *t;
    int i,k,j,sum=0;
    for(i=0;i<graph.vex;i++){
        for(k=0;k<graph.vex;k++){
            for(j=0;j<graph.vex;j++){
                sum+=(s.mats[i][j])*(graph.mats[j][k]);
            }
            t->mats[i][k]=sum;
            sum=0;
        }
    }
}

void jude2(int n){
    int i,k,sum=0;
    struct abc t = graph;
    for(int k=0;k<n-1;k++)
        count(&t);
    for(int i=0;i<graph.vex;i++)
        sum+=t.mats[i][i];
    if(sum>0) printf("�õ�������ͼ����Ϊ%d�Ļ�·��%d��\n",n,sum);
    else printf("�Ĵ�������ͼû�г���Ϊ%d��ͨ·\n",n);
    anst+=sum;
}
int main(){
    creat();
    output();
    for(int i=1;i<=4;i++){
        jude2(i);
        cout<<endl;
    }

    printf("������ͼ����С�ڵ���4�Ļ�·��%d��\n",ansh);
    printf("������ͼ����С�ڵ���4��ͨ·��%d��\n",anst);
    system("pause");
    return 0;

}

#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
int anst = 0,ansh = 0,dij[1000]= {0};
struct abc
{
    char vexs [100];
    int mats [100][100];
    int vex,side;
} graph;

int loc(char a)
{
    for(int i=0; i< graph.vex; i++)
        if(graph.vexs[i] == a) return i;
    return -1;
}

void creat( )
{
    int a1,a2,a3;
    cout<<"����������ͼ�����: ";
    cin>> graph.vex;
    cout<<"����������ͼ����:" ;
    cin>>graph.side;
    cout<<"����������ͼ�ĸ�����������: ";
    for(int i=0; i<graph.vex; i++) cin>>graph.vexs [i];
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
            graph.mats[i][j] = inf;
    }
    for(int i=0; i<graph.side; i++)
    {
        printf( "�����������%d���ߵ���������:",i+1);
        getchar();
        scanf("%c %c",&a1,&a2);
        cout<<"������ߵ�Ȩֵ:" ;cin>>a3;
        graph.mats[loc(a1)][loc(a2)]=a3;
        graph.mats[loc(a2)][loc(a1)]=a3;
    }
}

void output( )//������
{
    for(int i=0 ; i<graph. vex; i++)
    {
        for(int j=0; j<graph. vex; j++)
            cout<<graph.mats[i][j]<<" ";
        cout<<endl;
    }
}

void dijk()
{
    int n=graph.vex,min,k;
    bool s[1000];
    for(int i=0; i<n; i++)
    {
        s[i]=false;
        dij[i]=graph.mats[0][i];
    }
    s[0]=true ;
    dij[0]=0;
    for(int i=0; i<n; i++)
    {
        min=inf;
        for(int j=0; j<n;j++)
        {
            if ((!s[j]) && dij[j] < min){
                min=dij[j];
                k = j;
            }

        }
        s[k]=true;
        for(int j=0; j<n; j++)
        {
            if((!s[j]) && (dij[k]+graph.mats[k][j])<dij[j] )
                dij[j]=dij[k]+graph.mats[k][j];
        }
    }

    for(int w=0; w<graph.vex ;w++) printf("dij[%d]=%d\n",w,dij[w]);
}
int main(){
    creat();
    dijk();
    printf("�õ�V0��V5����̾���Ϊ��%d\n",dij[5]);
    system("pause");
    return 0;
}
*/

#includ<bits/stdc++.h>
using namespace std;

int list[100][100],n;
int listchange[100][100];
char point[100];
bool cmp(char a,char b)
if(a>b)return false;
else   return true;
}
int loc(char a)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        if(point[i] == a)
            return i;
    }
    return -1;
}
void output(int a)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(a == 1)  cout<<list[i][j]<<" ";
            else  cout<<listchange[i][j]<<" ";
        cout<<endl;
    }
}
void init()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            listchange[i][j]=list[i][j];
}
void r()
{
    for(int i=0; i<n; i++)
        listchange[i][i]=1;
}
void s()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(listchange[i][j] == 1 && listchange[j][i] == 0)listchange[j][i]=1;
}
void t()
{
    int i,j,k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(listchange[j][i]>=1)
            {
                for(k=0; k<n; k++)
                    listchange[j][k]=listchange[j][k]+listchange[i][k];
            }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(listchange[i][j]>1)listchange[i][j]=1;
}
int main()
{
    int i=0,j=0;
    char k,p;
    cout<<"����������������ƣ�(���롰 * �� ����)"<<endl;
    while(1)
    {
        cin>>k;
        if(k != '*') point[i++]=k;
        else break;
    }
    n=i;
    sort(point,point+n,cmp);
    cout<<"���趥��ֱ�Ϊ��"<<endl;
    while(j != n)
    {
        cout<<point[j++]<<" ";
    };
    cout<<endl;
    cout<<"��ֱ������������ߵ������㣺(���롰 <*,*> �� ����)"<<endl;
    while(1)
    {
        cout<<"<";
        k=getche();
        cout<<",";
        p=getche();
        cout<<">"<<endl;
        if(((k == '*')&&(p != '*'))||((k != '*')&&(p == '*')))cout<<"��������"<<endl;
        else
        {
            if((k == '*')&&(p == '*'))break;
            list[loc(k)][loc(p)]=1;
        }
    }
    cout<<"��ʼ��ϵ���������飺"<<endl;
    output(1);
    init();
    r();
    cout<<"�Է��հ���ϵ���������飺"<<endl;
    output(2);
    init();
    s();
    cout<<"�ԳƱհ���ϵ���������飺"<<endl;
    output(3);
    init();
    t();
    cout<<"���ݱհ���ϵ���������飺"<<endl;
    output(4);
    system("pause");//
    return 0;
}


