//ʵ��txt�ļ��Ķ��벢��д������һ��txt�ļ���~
#include<fstream>  //ifstream
#include<iostream>
#include<string>     //����getline()
//#include<cmath>
using namespace std;

int main() {
    string s;
    ofstream outf("in.txt",ios::out);
    ifstream inf;
    inf.open("in.txt");
    //������ļ�
    outf.open("out.txt");
    while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
    {
        outf << s << '\n';       //�����out�ļ��к���
        cout << s << endl;       //��������ư���
    }
    inf.close();
    outf.close();
    return 0;
}