#include<bits/stdc++.h>
#define INF 99999999 //ģ��������
#define MVNUM 100  //��󶥵���
typedef char vertexType; //��������
typedef int areType;     //��Ȩֵ����

typedef struct{
    vertexType vexs[MVNUM];//�����
    areType ares[MVNUM][MVNUM];//�ڽӱ�
    int vexNum;//�������
    int areNum;//����Ŀ
}AMGraph;

void creat(AMGraph &G){
    cin>>G.vexNum>>G.areNum;
    for(int i=1;i<=G.vexNum;i++)cin>>G.vexs[i];
    for(int i=1;i<=G.vexNum;i++)
        for(int j=1;j<=G.vexNum;j++)
            G.ares[i][j]=INF;
            int v1,v2,w;
    for(int i=1;i<=G.areNum;i++)
    {
        cin>>v1,v2,w;
        G.ares[v1][v2]=w;
    }
    return OK;
}

int main(){


    return 0;
}
