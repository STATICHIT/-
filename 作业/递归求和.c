#include<stdio.h>
void main()
{
    long long int N,j,S=0;
    long long int jiecheng(int i);///��������
    scanf("%d",&N);
        for(j=1; j<=N; j++)
        {
            S=S+jiecheng(j);       ///�����Ͷ���Ҫ����һ��
        }                          ///������Զ�����main����֮ǰ���Ͳ����ٴ�������
    printf("%lld",S);
}
  long long int jiecheng(int i)///���Ƕ���
{
    long long int s;
    if(i==1)
        s=1;
    if(i>1)
        s=jiecheng(i-1)*i;
    return(s);
}
//�������ˣ���û��ȫ������emmm
/*#include<stdio.h>
void main()
{
    long long int N,j,S=0,k=1;
    int jiecheng(int i);
    scanf("%d",&N);
        for(j=1; j<=N; j++)
        {
            k=k*j;
            S=S+k;
        }
    printf("%lld",S);
}
*/
