#include<bits/stdc++.h>
using namespace std;
int dday[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31}; //�·�����Ӧ��������һ�����鴢�棬����ȡ��
int dd,mm,yy,bd,bm,by;
bool check(int year,int month,int day)//�ж��Ƿ��Ǹ��Ϸ�����
{
    if(month > 12 || month < 1 || day < 1 || day > 31 || year < 1 || year > 99)//��Ŀֻ��֤�� �� �� �� �� �е��겻Խ��
        return false;
    else if(day > dday[month])//����������·ݵ��ж���
        return false;
    else if(year % 4 !=0 && month == 2 && day>28)
        return false;

    ///����ɹ���Ӫ���˴�˵���Ǹ��Ϸ����ڣ��ڴ˻����Ͻ����ж��Ƿ����

    //�ж��Ƿ����
    if(yy - year > 18)
        return true;
    else if(yy - year == 18 && mm - month > 0)
        return true;
    else if(yy - year == 18 &&mm - month == 0&&dd-day >= 0)
        return true;///else if������ָ������yy-year>18֮�����㣨�������������һ��Ҫ����yy-year==18���ǰ������
    else//�������������֮�ⶼ������
        return false;
}
int main()
{
    scanf("%d.%d.%d %d.%d.%d",&dd,&mm,&yy,&bd,&bm,&by);
    //ö�����ִ������check�ж�
         if(check(by,bm,bd)== true)cout<<"YES";
    else if(check(by,bd,bm) == true)cout<<"YES";
    else if(check(bm,by,bd) == true)cout<<"YES";
    else if(check(bm,bd,by) == true)cout<<"YES";
    else if(check(bd,by,bm) == true)cout<<"YES";
    else if(check(bd,bm,by) == true)cout<<"YES";
    else cout<<"NO";
    return 0;
}
