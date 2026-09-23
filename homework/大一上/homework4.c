/*程算1作业4.1最大最小单词简略版*/
/*
#include<stdio.h>
#include<string.h>

int main(){
char words[20][20];
int length=0,num=0,min=0,max=0;

for(num;length!=4;num++)
{
    printf("Enter word:");
    scanf("%s",words[num]);
    length=strlen(words[num]);
}

for(int n=0;n<num;n++)
{   if(strcmp(words[min],words[n])>0)
        min=n;
    if(strcmp(words[max],words[n])<0)
        max=n;
}

printf("Smallest word: %s\n",words[min]);
printf("Largest word: %s",words[max]);

return 0;
}
*/

/*程算1作业4.2逆序*/
/*
#include<stdio.h>
int main(){
char message[100];

printf("Enter a message:");

for(int i=0;i<100;i++)
{
    message[i]=getchar();
    if(message[i]=='\n')
        break;
}

for(int i=99;i>=0;i--)
{
    if(message[i]=='\n')
    {
        printf("Reversal is:");
        for(int m=i-1;m>=0;m--)
        {
        printf("%c",message[m]);
        }
        i=-1;
    }
}

return 0;
}
*/
/*程算1作业4.3栈*/
/*
#include <stdbool.h>   // C99 only
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

//external variables 
char contents[STACK_SIZE];
int top = 0;

void stack_overflow(void)
{
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Stack underflow\n");
  exit(EXIT_FAILURE);
}

void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(char ch)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}

char pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];

  return '\0'; //prevents compiler warning due to stack_underflow() call
}

char reverse(char sign)
{
    if(sign==')')
        return'(';
    else if(sign==']')
        return'[';
    else if(sign=='}')
        return'{';
}

int main(void)
{
    bool flag=false;
	char braces[STACK_SIZE]={'0'};

    printf("Enter parentheses and/or braces:");
    scanf("%s",braces);

    for(int i=0;i<STACK_SIZE;i++)
    {
        if (braces[i]==0)
            break;

        if(braces[i]=='('||braces[i]=='['||braces[i]=='{')
            push(braces[i]);
        else
        {
            if(!is_empty()&&reverse(braces[i])==contents[top-1])
                pop();
            else
                flag=false;
        }
    }

if(top==0)
flag=true;

    if(flag)
        printf("Parentheses/braces are nested properly");
    else
        printf("Parentheses/braces are NOT nested properly");
return 0;
}
*/