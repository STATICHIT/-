#include<stdio.h>
void main()
{
int n;
scanf("%d",&n);
long long a[50000+10];
//ѭ�������ʼ������a
for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
}
//����ǰ׺������
long long sum[50000+10];
sum[0]=0;
for(int i=1;i<=n;i++){//ע��˴��Ǵ�i=1��ʼѭ��
        sum[i]=sum[i-1]+a[i-1];
}//����sum[i]�ǵ�ǰǰ׺�ͣ�sum[i-1]��i-1��ǰ׺��
 //��a[i-1]��֮����Ҫ��1������Ϊ���Ǵ�i=1��ʼѭ��
 //�������Ǵ�a[0]��ʼ��Ҫi-1�Ŵ����Ӧ�������±�
int q;
scanf("%d",&q);
//q�����룬q�𽥼�С����q����0ʱֹͣ�Ӷ��ﵽq��ѭ����Ŀ��
while(q--){
    int l,len;
    scanf("%d %d",&l,&len);
    printf("%lld\n",sum[l+len-1]-sum[l-1]);
    //������Ϊ����ӵ�l��ʼlen�����ĺ�
    //������������ֱ�ӿ���ǰ׺��Ŷ����
    }
}
