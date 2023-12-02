#include<iostream>
#include<map>//使用map要加此头文件
using namespace std;

int main()
{
    map<int,string> m;
    m[1]="你不太好";
    m[1]="你好";//修改了关键字1对应的值
    m[2]="嗨";
    m[3]="今晚月色真美";
    m[4]="风也温柔";
    m[10]="适合刺猹";

    cout<<m[1]<<m[3]<<endl;
    cout<<m.size()<<endl;//返回map中的映射次数

    ///swap（）：交换两个map
    swap(m[1],m[3]);
    cout<<m[1]<<m[3]<<endl;

    ///map.count(key):存在返回1，不存在返回0
    ///返回指定元素出现的次数,因为key值不会重复，所以只能是1or0
    cout<<"2是否有索引值 "<<m.count(2)<<endl;
    cout<<"20是否有索引值 "<<m.count(20)<<endl;

    ///map.earse():删除一个元素
    m.erase(1);//删除了关键字为1的映射
    ///map.size():返回map中元素的个数
    cout<<m.size()<<endl;//变为4了

    ///map.empty():判断map是否为空，是返回1，非空返回1
    cout<<"map是否为空 "<<m.empty()<<endl;

    ///map.clear():清空
    m.clear();//清空
    cout<<"map是否为空 "<<m.empty()<<endl;
    cout<<m.size()<<endl;//映射次数变成0了

    return 0;
}
