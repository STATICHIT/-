//����Ҫ��С��������s�����ϣ�������4�����㣬Ȩֵ������Ҫ�Լ���
#include<bits/stdc++.h>
using namespace std;
int s,p;//pΪ������������������
int a,b,x[510],y[510];
int f[501],num;//numΪ������

struct EDGE
{
    int a,b;
    double v;
}e[250001];//��ΧҪ����500*500�ýṹ������洢�ߵĹ�ϵ����������

bool cmp(EDGE a,EDGE b)
{
    return a.v<b.v;//ʵ�ָ���v��С��������
}

int getf(int i)//���鼯�����ں���
{
    if(f[i] == i)
        return i;
    else
        return f[i]=getf(f[i]);//ѹ��·��
}

int hebing(int a,int b)
{
    if( getf(a) != getf(b) )
    {
        f[getf(b)]=getf(a);
        return 1;//˵�����������㲻��һ������,ѡ����Ȼ������Ǻϲ���һ����
    }
    else
    return 0;//˵��������������ͬһ�����ϣ���ɻ�������
}

double weight(int x,int y,int xx,int yy)//��������뼴Ȩֵ
{
    return sqrt((x - xx)*(x - xx) + (y - yy)*(y - yy));
}

int main()
{
    int i;
    cin>>s>>p;
    for(i=1;i<=p;i++)
    {
        f[i]=i;
        cin>>a>>b;
        x[i]=a;y[i]=b;
    }
    ///��Ȩֵ,���
    int k=0;
    for(i=1;i<=p;i++)
        for(int j=i+1;j<=p;j++)//����j=i+1,�����ظ���ߣ����Ϳռ�ʱ�临�Ӷ�
    {
        k++;
        e[k].a=i;e[k].b=j;
        e[k].v=weight(x[i],y[i],x[j],y[j]);
    }

    sort(e+1,e+1+k,cmp);//����Ȩֵ�����
    num=p;//������һ��ʼ���ڽ����
    //Kruskal
    for(i=1;i<=k;i++)
    {
        //�жϸñ����ӵ����������Ƿ���һ������
        if( hebing(e[i].a,e[i].b) == 1)
        {
            hebing(e[i].a,e[i].b);
            num--;
        }
        if(num == s)break;//������������sʱ������ʣ�µļ��Ͽ�����s�����ߵ��շ�������
    }
       printf("%.2 lf", e[i].v);//��i���ߵĳ��ȼ�Ϊ��Сֵ
}
