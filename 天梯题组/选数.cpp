#include<iostream>
using namespace std;

bool check(long long int i)
{
	while(i!=0)
	{
		int r=i%10;
		if(r==2||r==0||r==1||r==9)
		return true;
		i=i/10;
	}
	return false;
}

int main()
{
	long long int sum=0,i;
	for( i=1;i<=2019;i++)
	{
		if(check(i))
		sum+=i*i;

	}
	cout<<sum<<endl;
	return 0;
}
