/*
#include<stdio.h>
#include<string.h>
int main()
{
    int i,n=0;
    char a[200+10];
    gets(a);
    int l=strlen(a);
    for(i=0; i<l; i++)
    {
        switch(a[i])
        {
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case ' ':n=n+1;break;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x':n=n+2;break;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y':n=n+3;break;
        case 's':
        case 'z':n=n+4;break;
        }
    }
    printf("%d\n",n);
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100+5];
    int i,ans=0,n;
    scanf("%d",&n);
    scanf("%s",a);///������������ط�һ��
                  ///Ҫ��%s���룬��Ҳ��֪��Ϊʲô����
                  ///ѧ��˵����ȵ���Ŀ������%s
    //printf(a);//����ַ������������
    //printf("\n");
    for(i=0; i<strlen(a); i++)
    {
        if(a[i] == 'V'&&a[i+1] == 'K')
        {
            ans++;
            a[i]='a';
            a[i+1]='b';
        }
    }

    for(i=0; i<strlen(a); i++)
    {
        if(a[i] == a[i+1])
        {
            ans++;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    int i,x=0,y=0;
    char a[300];
    scanf("%s",a);
    int l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]=='b'&&a[i+1]=='o'&&a[i+2]=='y'){y++;i+=2;continue;}//����boyʱ
		if(a[i]=='b'&&a[i+1]=='o'){y++;i+=1;continue;}//����boʱ
		if(a[i]=='o'&&a[i+1]=='y'){y++;i+=1;continue;}//����oyʱ
		if(a[i]=='b'){y++;continue;}//����bʱ
		if(a[i]=='o'){y++;continue;}//����oʱ
		if(a[i]=='y'){y++;continue;}//����yʱ
		if(a[i]=='g'&&a[i+1]=='i'&&a[i+2]=='r'&&a[i+3]=='l'){x++;i+=3;continue;}//����girlʱ
		if(a[i]=='g'&&a[i+1]=='i'&&a[i+2]=='r'){x++;i+=2;continue;}//����girʱ
		if(a[i]=='g'&&a[i+1]=='i'){x++;i+=1;continue;}//����giʱ
		if(a[i]=='i'&&a[i+1]=='r'&&a[i+2]=='l'){x++;i+=2;continue;}//����irlʱ
		if(a[i]=='r'&&a[i+1]=='l'){x++;i+=1;continue;}//����rlʱ
		if(a[i]=='i'&&a[i+1]=='r'){x++;i+=1;continue;}//����irʱ
		if(a[i]=='g'){x++;continue;}//����gʱ
		if(a[i]=='r'){x++;continue;}//����rʱ
		if(a[i]=='i'){x++;continue;}//����iʱ
		if(a[i]=='l'){x++;continue;}//����lʱ
    }
    printf("%d\n%d\n",y,x);
    return 0;
}
*/

/*
///��ȱ�С��
//����˼·������Ϊ���ʳ���С��100������һ����ĸ������100��,
����������С�����Ĳ�����100�������ȶ���һ��100��������
�����鸳ֵ���ã�����ĸ�ĳ��ִ�����sum[26]��ÿ��Ԫ�س�ʼ��Ϊ0��
����¼��ÿ����ĸ��������ĸ���е�˳���������������ÿ����ĸ��
��sum[s[i]-'a']++;�ﵽ��¼ÿ����ĸ���ִ�����Ŀ�ģ�������ѭ��
�ó����ִ��������ֵ����Сֵ��������ֻ��ans��isPrime�����е�
ÿ����ȥ�ȶԣ����������������������Ӧ��������ѭ����Ҳû
�ȶ���һ���������������һ�ֶ�Ӧ�����

*/
/*
#include<stdio.h>
#include<string.h>
int main()
{
    int isPrime[100],i,j,k=0;
    for(i=2; i<100; i++) //��isPrime���鸳ֵ����
    {
        for(j=2; j<=i; j++)
        {
            if(i%j == 0)
                break;
        }
        if(j == i)
            isPrime[k++]=i;
    }//100�ڵ�������Ϊk-1��

    //for(i=0;;i++)//���100�����������鸳ֵ���
    //{
    //    printf("%d ",isPrime[i]);
    //    if(isPrime[i] == 97)//�׵�100���������Ϊ97
    //        break;
    //}

    char s[101];//���жϵ���
    int sum[27]= {0}; //�������ڼ�¼��i����ĸ�ĸ���
    gets(s);
    for(i=0; i<strlen(s); i++)
    {
        sum[s[i]-'a'+1]++;//��s[i]Ϊa����sum[s[i]-'a'+1]Ϊsum[1]�����1����ĸa���ִ���
    }///�о�����˵�������õ���������Ͱ�ŵ�˼��       �˴�û�õ�sum[0]��Ϊ�˱������
    int max=sum[0],min=100;;//��ʼ��max��min
    for(i=0; i<26; i++)
    {
        if(sum[i]>0)
        {
        if(max<sum[i])
            max=sum[i];
        if(min>sum[i])
            min=sum[i];
        }
    }
    //printf("max=%d,min=%d\n",max,min);//��������С��������
    int ans=max-min;
    //printf("ans=%d\n",ans);//���ans�������
    for(i=0; i<k-1; i++)
    {
        if(ans == isPrime[i])
        {
            printf("Lucky Word\n%d\n",ans);
            return 0;
        }
    }
    if(i == k-1)
        printf("No Answer\n0\n");
    return 0;
}

*/

/*
#include<stdio.h>
#include<string.h>
#include<math.h>
int l(int n)
{
    int i,l;
    if(n>=0)
    {
        for(i=0;; i++)
        {
            if(n/pow(10,i)<1)
            {
                l=i;
                return(l);
            }
            else if(n/pow(10,i) == 1)
            {
                l=i+1;
                return(l);
            }
        }
    }
    if(n<0)
    {
        n=-1*n;
        for(i=0;; i++)
        {
            if(n/pow(10,i)<1)
            {
                l=i;
                return(l+1);
            }
            else if(n/pow(10,i) == 1)
            {
                l=i+1;
                return(l+1);
            }
        }

    }

}
int main()
{
    int t,k,i,j;
    char s[20];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        //printf(s);���s���鸳ֵ
        if(s[0] == 'a')
            k=1;//k=1����ӣ�
        else if(s[0] == 'b')
            k=2;//k=2�������
        else if(s[0] == 'c')
            k=3;//k=3����ˣ�

        int n1=0,n2=0,l1=0,l2=0;

        //���²��������ϵ�һ����
        for(i=0; i<strlen(s); i++)
        {
            if(s[i] == ' '&&s[i-1]>='0'&&s[i-1]<='9')
            {
                for(j=i-1;; j--)
                {
                    if(j == -1||s[j] == ' ')
                    {
                        break;
                    }
                    n1=n1+(s[j]-'0')*pow(10,i-j-1);
                    l1++;
                }
                break;//��Ϊ�˴���break�Ͳ�����ִ��for�е�i++��
            }
        }
        //printf("n1=%d l1=%d ",n1,l1);//���n1��ֵ���

        //���²��������ϵڶ�����
        for(j=i+1; j<strlen(s); j++)
        {
            n2=n2+(s[j]-'0')*pow(10,strlen(s)-1-j);
            l2++;
        }
        //printf("n2=%d\n l2=%d \n",n2,l2);//���n2��ֵ���

        if(k == 1)
        {
            printf("%d+%d=%d\n%d\n",n1,n2,n1+n2,l(n1+n2)+l1+l2+2);
        }
        else if(k == 2)
        {
            printf("%d-%d=%d\n%d\n",n1,n2,n1-n2,l(n1-n2)+l1+l2+2);
        }
        else if(k == 3)
        {
            printf("%d*%d=%d\n%d\n",n1,n2,n1*n2,l(n1*n2)+l1+l2+2);
        }
    }
    return 0;
}

*/

/*
//�������
#include<stdio.h>
int main()
{
    int a[10][10],i,j;
    for(i=0; i<10; i++)
    {
        a[i][0]=1;
        a[i][i]=1;
        if(i>1)
        {
            for(j=1; j<i; j++)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
    }
    for(i=0; i<10; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    int i,k=0;
    gets(a);
    gets(b);
    if(strlen(b)>=5)
    {
        for(i=strlen(a); i<strlen(a)+5+1; i++)
        {
            a[i]=b[k++];
        }
        a[i]='\0';
        printf(a);
    }
    if(strlen(b)<5)
    {
        for(i=strlen(a); i<=strlen(a)+strlen(b); i++)
        {
            a[i]=b[k++];
        }
        a[i]='\0';
        printf(a);
    }
}
*/
