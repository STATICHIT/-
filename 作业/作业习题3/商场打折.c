#include<stdio.h>
int main()
{
    float finalPrice(char isVip,float count,float price);
    char vip;
    float exchangeCount,price,sum;
    printf("is Vip?true input'T'or't',or the other key:");
    scanf("%c",&vip);
    printf("Please input the price:");
    scanf("%f",&price);
    printf("Please input the count:");
    scanf("%f",&exchangeCount);
    sum=finalPrice(vip,exchangeCount,price);
    printf("The total is:%f\n",sum);
    return 0;
}

float finalPrice(char isVip,float count,float price)
{
    if(isVip=='t'||isVip=='T')
        return 0.7*count*price;
    else
        return count*price;
}
