 #include<stdio.h>
void main()
{
    int N;
    int jiecheng(int N);//����ʱ��Ҫ���˼ӷֺ�
    scanf("%d",&N);
    if(N>0)//��ֹϵͳ��⸺��ʱ����
        printf("%d",jiecheng(N));
}
int jiecheng(int N)
    {
        int s;
        if(N==0||N==1)
            s=1;
        if(N>1)//�˴�Ϊ�ݹ�����
            s=jiecheng(N-1)*N;//�˴������˵ݹ��ϵ
                    return(s);//��s���ص�����ֵ��
        //�����������õõ��ľ���N�Ľ׳����ֵ
    }
