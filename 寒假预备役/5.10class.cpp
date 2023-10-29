#include<bits/stdc++.h>
#define INF 99999999 //模拟正无穷
#define MVNUM 100  //最大顶点数
typedef char vertexType; //顶点类型
typedef int areType;     //边权值类型

typedef struct{
    vertexType vexs[MVNUM];//顶点表
    areType ares[MVNUM][MVNUM];//邻接表
    int vexNum;//顶点个数
    int areNum;//边数目
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
