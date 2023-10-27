/*
//Hanoi
#include<stdio.h>
void move(char x,char y)
{
    printf("%c->%c\n",x,y);
}
void hanoi(int n,char one,char two, char three)
{
    if(n==1)
        move(one,three);
    else
    {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}
void main()
{
 int m;
 scanf("%d",&m);
 hanoi(m,'A','B','C');
}
*/
#include<stdio.h>
void hanoi(int n,char x,char y,char z)
{
    if(n == 1)
    {
        printf("%c->%c\n",x,z);
    }
    else
    {
        hanoi(n-1,x,z,y);
        printf("%c->%c\n",x,z);
        hanoi(n-1,y,x,z);
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    hanoi(m,'A','B','C');
    return 0;
}
/*
#include<stdio.h>
int move(char x,char y)
{
    printf("%c->%c\n",x,y);
}
int hanoi(int n,char one,char two,char three)
{
    if(n ==1)
        move(one,three);
    else
        {hanoi(n-1,one,three,two);
          move(one,three);
         hanoi(n-1,two,one,three);
        }
}
int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}
*/
