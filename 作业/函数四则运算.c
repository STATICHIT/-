#include<stdio.h>
void main()
{
    int n,i,a,b;
    char x,y,z;
    int add(int a,int b);
    int mul(int a,int b);
    int sub(int a,int b);
    float div(int a,int b);

    while(~scanf("%d",&n))
    {
        getchar();
        for(i=1; i<=n; i++)
        {
            scanf("%c%c%c(%d,%d)",&x,&y,&z,&a,&b);
            getchar();
            switch(x)
            {

            case'a':
                    printf("%d\n",add(a,b));
                break;
            case'm':
                printf("%d\n",mul(a,b));
                break;
            case's':
                printf("%d\n",sub(a,b));
                break;
            case'd':
                    div(a,b);
                break;
            }
        }

    }
}
int add(int a,int b)
{
    return(a+b);
}
int mul(int a,int b)
{
    return(a*b);
}
int sub(int a,int b)
{
    return(a-b);
}
float div(int a,int b)
{
    if(b==0)
    {
        printf("error\n");
    }
    else if(a%b==0)
    {
        printf("%d\n",a/b);
    }
    else if(a%b!=0)
    {
        printf("%.2f\n",a*1.0/b);//����ʱ����һ��Ҫ��С����������a*0.1�����ؼ�
    }
}


//�ĵã���̫�����������ս�߲��������Сʱ������������̫̫̫�����ˣ�����
///��Ŀ������ B: �������㺯��

//  ��򵥵���ͺ������ƣ�������β�������20���ڵ�����ˡ����Ƕ������ĸ�������add(a,b)=a+b; sub(a,b)=a-b; mul(a,b)=a*b; div(a,b)=a/b��������ǵ�ֵ��
//a b ��������
//��ʽ
//�����ʽ
//���������ж��顣
//��һ������n��������n������n������������֤�ǵ������㣬��������磺add(add(a,b),c)�����������
//�����ʽ
  //˳�������Ӧ������ֵ��
// ÿ�����ռһ�С�
// ���������У�����Ϊ0ʱ�����error�����õ����̲��������ı�����λС����
