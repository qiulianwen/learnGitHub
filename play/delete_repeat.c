#include<stdio.h>
int main()
{
char a[30],input;
int time[26]={0},i=0;

while(input!='\n')
{
    input=getchar();
    time[input-'a']+=1;
    if(time[input-'a']==1)
        {a[i]=input;
        i++;}

}

for(int x=0;x<i;x++)
printf("%c",a[x]);

return 0;
}