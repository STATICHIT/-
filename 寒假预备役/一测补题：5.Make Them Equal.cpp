#include<bits/stdc++.h>
using namespace std;

int n,t,b[200010],a[200010];
int main()
{
	cin>>t;
	while(t--)
	{
	    cin>>n;
		int i,j,k,sum=0;

		for(i=1;i<=n;i++)
		{
		    cin>>a[i];
			sum+=a[i];
			b[i]=a[i]%i;//由b【i】*i=a【i】，使得后续a【i】-i*b【i】=0。把数都累加到a1上
		}
		if( sum/n != 1.0*sum/n )//若平均数不是整数则无法使序列中每个元素相同
		{
			cout<<"-1"<<endl;
			continue;//结束这组判断，进行下一组数据判断
		}
		int step=3*(n-1);
		cin>>step;
		for(i=2;i<=n;i++)
		{
			printf("1 %d %d\n",i,(i-b[i])%i);//使a[i]是i的整数倍，这里有(n-1)次操作
			if( a[i] % i != 0 )//当a[i]不是i的整数倍时进行此操作，是整数倍的话操作前后数据不变
			{
				a[1]-=((i-b[i])%i)*1;//此时i=1 ,提前将余数加到a[1]里面，不然后面无法得到预期的平均数
				a[i]+=((i-b[i])%i)*1;//这里a[i]-余数后，即此时a[i]为i的整数倍
			}
			printf("%d 1 %d\n",i,a[i]/i);//把a[i]转移到a[1]上，这里有(n-1)次操作
			a[1]=a[1]+a[i];
			a[i]=0;
		}
		for(i=2;i<=n;i++)
		{
			printf("1 %d %d\n",i,sum/n);//将a[1]的值平均分给每个a[i],这里有(n-1)次操作,共3*（n-1）次操作
			//a[1]-=sum/n;
			//a[i]=sum/n;//因为这是最后一步操作了且结果确定了，操作过程与a【i】其实没有实质性的关系了，且题目不要求把每次操作后的a【i】写出来所以可以不算出来
		}
	}
	return 0;
}
