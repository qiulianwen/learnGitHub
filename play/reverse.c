#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
char a[20],temp;
int i=0;

for (int x=0;temp!='\n';x++)
{
    temp=getchar();
    a[x]=temp;
}

i=strlen(a);

for (int num=i-2;num>=0;num--) 
{
    for(int out=i-2;out>=num&&out<=i-2;out--)
    {
        printf("%c",a[out]);
    }
printf(" ");
}
printf("\n");

system("pause");
return 0;
}