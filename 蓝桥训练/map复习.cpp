#include<iostream>
#include<map>//ʹ��mapҪ�Ӵ�ͷ�ļ�
using namespace std;

int main()
{
    map<int,string> m;
    m[1]="�㲻̫��";
    m[1]="���";//�޸��˹ؼ���1��Ӧ��ֵ
    m[2]="��";
    m[3]="������ɫ����";
    m[4]="��Ҳ����";
    m[10]="�ʺϴ��";

    cout<<m[1]<<m[3]<<endl;
    cout<<m.size()<<endl;//����map�е�ӳ�����

    ///swap��������������map
    swap(m[1],m[3]);
    cout<<m[1]<<m[3]<<endl;

    ///map.count(key):���ڷ���1�������ڷ���0
    ///����ָ��Ԫ�س��ֵĴ���,��Ϊkeyֵ�����ظ�������ֻ����1or0
    cout<<"2�Ƿ�������ֵ "<<m.count(2)<<endl;
    cout<<"20�Ƿ�������ֵ "<<m.count(20)<<endl;

    ///map.earse():ɾ��һ��Ԫ��
    m.erase(1);//ɾ���˹ؼ���Ϊ1��ӳ��
    ///map.size():����map��Ԫ�صĸ���
    cout<<m.size()<<endl;//��Ϊ4��

    ///map.empty():�ж�map�Ƿ�Ϊ�գ��Ƿ���1���ǿշ���1
    cout<<"map�Ƿ�Ϊ�� "<<m.empty()<<endl;

    ///map.clear():���
    m.clear();//���
    cout<<"map�Ƿ�Ϊ�� "<<m.empty()<<endl;
    cout<<m.size()<<endl;//ӳ��������0��

    return 0;
}
