//实现txt文件的读入并重写入另外一个txt文件中~
#include<fstream>  //ifstream
#include<iostream>
#include<string>     //包含getline()
//#include<cmath>
using namespace std;

int main() {
    string s;
    ofstream outf("in.txt",ios::out);
    ifstream inf;
    inf.open("in.txt");
    //打开输出文件
    outf.open("out.txt");
    while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
    {
        outf << s << '\n';       //输出到out文件中后换行
        cout << s << endl;       //输出到控制板上
    }
    inf.close();
    outf.close();
    return 0;
}