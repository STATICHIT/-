/*
//dfs
#include<stdio.h>
int a[10],book[10],n;//�˴��ر�˵��һ�£�C���Ե�ȫ�ֱ�����û�и�ֵ��ǰĬ��Ϊ0����������
//book��������ȫ���ٴθ���ʼֵΪ0����Ϊ�Զ��庯����Ҫ�õ�a��book�������Զ���ȫ�ֱ�����
void dfs(int step)//step��ʾ����վ�ڵڼ���������ǰ
{
    int i;
        if(step == n+1)//���վ�ڵ�n+1��������ǰ�����ʾǰn�������Ѿ��ź�
        {
            //���һ�����У�ǰ1��n�ź����е�����˳��
            for(i=1;i<=n;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");

        return;//����֮ǰ��һ�������һ�ε���dfs�����ĵط���
        }
    //��ʱվ�ڵ�step��������ǰ��Ӧ�÷��������أ�
    //����1��2��3...n��˳��һһ����
    for(i=1; i<=n; i++)
    {
        //�ж��˿����Ƿ�������
        if(book[i] == 0)//book[i]����0��ʾi���˿���������
        {
            //��ʼ����ʹ���˿���i
            a[step]=i;//��i�����step��������
            book[i]=1;//��book[i]��Ϊ1��ʾ�˿���i�Ѳ�������

            //��step�������Ѿ��ź��˿��ƣ���������Ҫ�ߵ���һ��������ǰ
            dfs(step+1);//�ݹ�
            book[i]=0;//���ղų��Ե��˿����ջ����У����ܽ�����һ�γ���
        }
    }
    return;///������һ�εݹ����
}
int main()
{
    //��������Ŀ��Ҫ��1��n��ȫ����Ŷ
    scanf("%d",&n);//�����ʱ��Ҫע��nΪ1��9֮�������
    dfs(1);//����վ��1��С����ǰ��
    return 0;
}
*/
/*
#include<stdio.h>
int n,a[10],book[10];
void dfs(int step)
{
    if(step == n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%d",a[i]);
        printf("\n");

        return;//ע��λ��
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i] == 0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
*/
#include<stdio.h>
int n,book[10],a[10];
void dfs(int step)
{
    if(step == n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%d",a[i]);
        printf("\n");

        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(book[i] == 0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
