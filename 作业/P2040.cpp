#include<iostream>
using namespace std;
int a[5][5],ans=0,mni=10;
void fun(int x,int y)//����
{
    //Ϊ1ʱ��1-1=0���任�ɹ�
    //Ϊ0ʱ��1-0=1���任�ɹ�
    //�~~ovo
    a[x][y]=1-a[x][y];
    a[x+1][y]=1-a[x+1][y];
    a[x][y+1]=1-a[x][y+1];
    a[x-1][y]=1-a[x-1][y];
    a[x][y-1]=1-a[x][y-1];
}
void dfs(int k)//����
{
    if(k>mni)return;
    int s=0;//����״̬�ĵ�����
    for(int i=1; i<=3; i++)//���㿪�Ƶ�����
        for(int j=1; j<=3; j++)
            s+=a[i][j];
    if(s==9){//�Ѵﵽȫ��״̬��������Сֵ
        ans=k-1;
        mni=min(ans,mni);
    }
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++){
            fun(i,j);
            dfs(k+1);
            fun(i,j);//���ݣ��ٰ�һ�ε���û�����൱�ڻ���
        }
    return;
}
int main()
{
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            cin>>a[i][j];

    dfs(1);//����
    cout<<mni;
    return 0;
}
