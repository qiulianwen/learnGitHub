//文件在E:\c-learing
#include <stdio.h>
#include<stdlib.h>

int main() {
int i=0,size=0;
long long input_1,input_2;

scanf("%lld",&input_1);

input_2=input_1;
//计算位数
while(input_1>0)
{
    input_1/=10;
    size++;
}

int a[size];
//填入数组
while(i<size)
{
    a[i]=input_2%10;
    input_2/=10;
    i++;
}
//输出
for(int j=size-1;j>=0;j--)
{
    if((j+1)%3==0&&j!=size-1)
    printf(",%d",a[j]);
    else
    printf("%d",a[j]);
}
printf("\n");

system("pause");
return 0;
}
