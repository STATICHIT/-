#include<stdio.h>
struct node
{
    int x;//������
    int y;//������
    int s;//����
} que[2501]; //��ͼ��С������50*50�����Զ�����չ���ᳬ��2500��
int a[51][51];//�����ͼ
int book[51][51];//��book��������Щ���Լ��ڶ������ˣ���ֹһ���㱻�ظ���չ��
//tip��ȫ�ֱ���Ĭ������Ԫ�س�ʼ��Ϊ0
int main()
{
    //����һ�����ڱ�ʾ�ߵķ��������
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
    //k������ö�ٷ���n��m����ͼ��С��startx��starty��������ꣻp��q���յ����ꣻtx��ty����չ�����ꡣflag������Ƿ񵽴��յ㡣
    //�����ͼ
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);//���������յ�����
    ///��ʼ���ն���
    int head=1;
    int tail=1;
    //�����в����������
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].s=0;
    tail++;
    book[startx][starty]=1;

    flag=0;
    while(head<tail)//�����в�Ϊ��ʱѭ��
    {
        //ö��4������
        for(k=0; k<4; k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            //�ж��Ƿ�Խ��
            if(tx<1||tx>n||ty<1||ty>m)
                continue;

            //�ж��Ƿ����ϰ����������·����
            if(a[tx][ty]==0&&book[tx][ty]==0)
            {
                //���������Ϊ�Ѿ��߹�
                book[tx][ty]=1;//ע�����ÿ����ͨ�������ֻ���һ�Σ������Ѳ�ͬ������Ҫ��book���黹ԭ����
                //��������չ��
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].s=que[head-1].s+1;//�����Ǹ��׵Ĳ���+1
                tail++;
            }
            if(tx == p&&ty == q)//�����յ����Ƴ�ѭ��
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
        head++;//ע������ط�ǰ���������ǣ���һ����չ�������head++���ܶ���һ����չ�������չ
    }
    //��ӡĩβ���һ���㣨Ŀ��㣩�Ĳ���
    //ע��tail��ָ����еĶ�β����һ��λ�ã�������Ҫ��һ
    printf("%d",que[tail-1].s);
    return 0;
}
