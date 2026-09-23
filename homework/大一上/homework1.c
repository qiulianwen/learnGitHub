/*程算1作业1.1分数加法*/
/*
#include <stdio.h>
int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;

	printf("Enter two fraction seperated by a plus sign:");
	scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

	result_num = num1*denom2 + num2*denom1;
	result_denom = denom1*denom2;
	printf("The sum is %d/%d\n", result_num, result_denom);

	return 0;
}
*/

/*程算1作业1.2日期格式转化*/
/*
#include<stdio.h>
int main()
{
int year,month,day;
printf("请输入日期");
scanf("%d/%d/%d",&month,&day,&year);
printf("%4d%02d%02d",year,month,day);//02表示不足用0占位
return 0;
}
*/

/*程算1作业1.3还贷计算*/
/*
#include<stdio.h>
int main()
{
float loan,rate,payment,monthly_rate,balance;
short int month=1;

printf("Enter amout of loan");
scanf("%f",&loan);
printf("Enter interest rate");
scanf("%f",&rate);
printf("Enter monthly payment");
scanf("%f",&payment);

monthly_rate=rate/100/12;
loan=loan*(1+monthly_rate)-payment;
printf("Balance remaining after first payment:$%.2f\n",loan);

monthly_rate=rate/100/12;
loan=loan*(1+monthly_rate)-payment;
printf("Balance remaining after second payment$:%.2f\n",loan);

monthly_rate=rate/100/12;
loan=loan*(1+monthly_rate)-payment;
printf("Balance remaining after third payment$:%.2f\n",loan);

return 0;
}
*/

/*程算1作业1.4计算账单*/
/*
#include<stdio.h>
int main()
{
int amount,twenty,ten,five,one;
printf("Enter a dollar amount: ");
scanf("%d",&amount);

twenty=amount/20;
amount%=20;

ten=amount/10;
amount%=10;

five=amount/5;

one=amount%5;
printf("$20 bills:%d\n$10 bills:%d\n$5 bills:%d\n$1bills:%d",twenty,ten,five,one);
return 0;
}
*/

/*程算1作业1.5计算税金*/
/*
#include<stdio.h>
int main()
{
float amount;
printf("Enter an amount:");
scanf("%f",&amount);
printf("with tax added:%.2f",amount*1.05);
return 0;
}
*/