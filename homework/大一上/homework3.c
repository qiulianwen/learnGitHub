/*程算1作业3.1凯撒加密*/
/*
#include<stdio.h>
int main()
{
char message[50]; 
int shift_amount,i;

printf("Enter message to be encrypted:");
//不能用scanf("%s",&message);
gets(message);
printf("Enter shift amount (1-25):");
scanf("%d",&shift_amount);

for(i=0;i<50;i++)
{
	if(message[i]>=65&&message[i]<=90)
	{
		if(message[i]+shift_amount>90)
		{
			message[i]=message[i]+shift_amount-26;
		}
		else
		message[i]=message[i]+shift_amount;
	}
	else  if(message[i] >= 97 && message[i] <= 122)
	{
		if(message[i]+shift_amount>122)
			message[i]=message[i]+shift_amount-26;
		else
			message[i]=message[i]+shift_amount;
	}

}

printf("Encrypted message:");
printf("%s", message);

return 0;
}
*/

/*程算1作业3.2随机步法*/
/*
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
char a[10][10];
char index=66;
int step;

for(int n=0;n<10;n++)
{

	for(int m=0;m<10;m++)
	{
		a[m][n]='.';
	}
}

a[0][0]='A';
//生成随机数
srand(time(NULL));

int i=0,j=0;
while(index<91)
{
    step=rand();
	step%=4;

	if(a[i+1][j]!='.'&&a[i-1][j]!='.'&&a[i][j+1]!='.'&&a[i][j-1]!='.')
	break;

	switch(step)
	{
	case 0:
		if(i-1<0||a[i-1][j]!='.')
			break;
		else 
			{a[i-1][j]=index;
			i-=1;
			index+=1;
			break;}
	case 1:
		if(j+1>9||a[i][j+1]!='.')
			break;
		else 
			{a[i][j+1]=index;
			j+=1;
			index+=1;
			break;}
	case 2:
	if(i+1>9||a[i+1][j]!='.')
		break;
	else 
		{a[i+1][j]=index;
		i+=1;
		index+=1;
		break;}
	case 3:
	if(j-1<0||a[i][j-1]!='.')
		break;
	else 
	{a[i][j-1]=index;
	j-=1;
	index+=1;
	break;}
	}
}

for(int n=0;n<10;n++)
{

	for(int m=0;m<10;m++)
	{
		printf("%c",a[m][n]);
	}
	printf("\n");
}

return 0;
}
*/

/*程算1作业3.3出现次数*/
/*
#include <stdio.h>

int main() {
	int digit, digit_count[10] = { 0 };
	long num;
	printf("Enter a number: ");
	scanf("%ld", &num);

	if (num == 0) {
		digit_count[0] = 1;
	}

	while (num != 0) 
	{
		digit = num % 10;
		digit_count[digit]++;
		num = num / 10;
	}

	printf("\nDigit:      ");

	for (int i = 0; i < 10; i++) {
		printf("%d", i);
	}
	printf("\nOccurrences:");
	for (int i = 0; i < 10; i++) {
		printf("%d", digit_count[i]);
	}
	return 0;
}
*/
/*程算1作业3.4表达式求值*/
/*
#include<stdio.h>
int main()
{
printf("Enter an expression:");
float sum,num;
char ch;

scanf("%f",&sum);

while((ch=getchar())!='\n')//scanf(" %c%lf", &ch, &num) == 2
{
	scanf("%f",&num);
	switch (ch)
	{
	case '+':
		sum+=num;
		break;
	case '*':
		sum*=num;
		break;
	case '-':
		sum-=num;
		break;
	case '/':
		sum/=num;
		break;	
	}
}

printf("Value of expression:%.3f",sum);

return 0;
}
*/
/*程算1作业3.5翻译*/
/*
#include<stdio.h>
int main(){
char input[50];

printf("Enter phone number:");
scanf("%s",input);

for(int i=0;i<50;i++)
{
		if(input[i]>=65&&input[i]<=90)
		{
			if (input[i]>=65&&input[i]<=67)
				input[i]='2';
			else if (input[i]>=68&&input[i]<=70)
				input[i]='3';
			else if (input[i]>=71&&input[i]<=73)
				input[i]='4';
			else if (input[i]>=74&&input[i]<=76)
				input[i]='5';
			else if (input[i]>=77&&input[i]<=79)
				input[i]='6';
			else if (input[i]>=80&&input[i]<=83)
				input[i]='7';
			else if (input[i]>=84&&input[i]<=86)
				input[i]='8';
			else if (input[i]>=87&&input[i]<=90)
				input[i]='9';
		}
}

printf("%s",input);

return 0;
}
*/