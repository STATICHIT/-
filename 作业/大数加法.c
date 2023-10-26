#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,sumlen;
    char a[510],b[510],result[510];
    scanf("%s",a);
    scanf("%s",b);
    int alen=strlen(a),blen=strlen(b);
    sumlen=alen>blen?alen:blen;//结果的长度最大只会比较大的数多一位
    sumlen+=1;//字符数组中末位自动还有个'\0'
    for()
        还不太会写，等我字符串熟练了再来写！





}







/*学长写的
#include <stdio.h>
#include <string.h>
int main()
{
    char a[510],b[510];
    scanf("%s",a);
    scanf("%s",b);
    int i, alen = strlen(a), blen = strlen(b);
    for(i=0;i<alen/2;i++){
        char ch = a[i];
        a[i] = a[alen - 1 - i];
        a[alen - 1 - i] = ch;
    }
    for(i=0;i<blen/2;i++){
        char ch = b[i];
        b[i] = b[blen - 1 - i];
        b[blen - 1 - i] = ch;
    }
    char ans[510];
    int temp = 0;
    for(i=0; i < alen && i < blen; i++){
        int val = a[i] - '0' + b[i] - '0' + temp;
        temp = val/10;
        val = val%10;
        ans[i] = val+'0';
    }
    while(i<alen){
        int val = a[i] - '0' + temp;
        temp = val/10;
        val = val%10;
        ans[i] = val+'0';
        i++;
    }
    while(i<blen){
        int val = b[i] - '0' + temp;
        temp = val/10;
        val = val%10;
        ans[i] = val+'0';
        i++;
    }
    if(temp!=0){
        ans[i] = temp+'0';
        i++;
    }
    ans[i] = '\0';
    int ansLen = strlen(ans);
    for(i=ansLen-1;i>=0;i--){
        printf("%c",ans[i]);
    }
}
*/
#include<stdio.h>
#include<string.h>
void main()
{
    char a[500+10];//初始化a，b数组
    gets(a);
    char b[500+10];
    gets(b);
    int i;
    int alen=strlen(a);
    int blen=strlen(b);
    for(i=0;i<alen/2;i++)//逆转a，b字符串数组便于计算
    {
        char ch=a[i];
        a[i]=a[alen-1-i];
        a[alen-1-i]=ch;
    }
    for(i=0;i<blen/2;i++)
    {
        char ch=b[i];
        b[i]=b[blen-1-i];
        b[blen-1-i]=ch;
    }
    char ans[500+10];//相同长度部分相加
    int temp=0;
    for(i=0;i<alen&&i<blen;i++)
    {
        int val=a[i]-'0'+b[i]-'0'+temp;
        temp=val/10;
        val=val%10;
        ans[i]=val+'0';
    }
    while(i<alen)
    {
        int val=a[i]-'0'+temp;
        temp=val/10;
        val=val%10;
        ans[i]=val+'0';
        i++;
    }
    while(i<blen)
    {
        int val=b[i]-'0'+temp;
        temp=val/10;
        val=val%10;
        ans[i]=val+'0';
        i++;
    }
    if(temp!=0)//考虑最高位是否要进一
    {
        ans[i]=temp+'0';
        i++;
    }
    ans[i]='\0';//字符数组要以'\0'结尾
    int anslen=strlen(ans);//恢复顺序输出
    for(i=anslen-1;i>=0;i--)
    {
        printf("%c",ans[i]);
    }
    printf("\n");
}

