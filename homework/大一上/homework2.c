/*程算1作业2.1日历*/
/*
#include<stdio.h>
int main()
{
    int days,start;
    printf("Enter number of days in month:");
    scanf("%d",&days);

    printf("Enter starting day of the week(1=Sun, 7=Sat):");
    scanf("%d",&start);

    printf("日 一 二 三 四 五 六\n");

    for (int i=1;i<start;i+=1)
    {
    p   rintf(" ");
    }

    for (int day=1;day<=days;day+=1)
    {
        printf("%3d",day);

    if((start-1+day)%7==0)
    {
        printf("\n");
    }

}
return 0;
}
*/

/*程算1作业2.2偶数平方*/
/*
#include<stdio.h>
int main()
{
    int n,i=2;
    printf("Enter a number:");
    scanf("%d",&n);

    while (i*i<=n)
    {
        printf("%d\n",i*i);
        i+=2;
    }

    return 0;
}
*/

/*程算1作业2.3股经纪人的佣金*/
/*
#include <stdio.h>
int main(void)
{
	float commission, value;

	printf("Enter value of trade: ");
	scanf("%f", &value);

    while(value!=0)
    {
    	if (value < 2500.00f)
    	    commission = 30.00f + .017f * value;
	    else if (value < 6250.00f)
	        commission = 56.00f + .0066f * value;
	    else if (value < 20000.00f)
	        commission = 76.00f + .0034f * value;
	    else if (value < 50000.00f)
	        commission = 100.00f + .0022f * value;
	    else if (value < 500000.00f)
	        commission = 155.00f + .0011f * value;
	    else
	        commission = 255.00f + .0009f * value;

	    if (commission < 39.00f)
	        commission = 39.00f;

	    printf("Commission: $%.2f\n\n", commission);
        printf("Enter value of trade: ");
	    scanf("%f", &value);
    }
  	return 0;
}
*/

/*程算1作业2.4最大公约数*/
/*
#include<stdio.h>
    int m,n,answer;
    nt main()
    {
    printf("Enter two integers:");
    scanf("%d %d",&m,&n);

    if (n==0)
        printf("Greatest common divisor:%d",m);

    while(n!=0)
    {
        answer=m%n;
        m=n;
        n=answer;
    }
    printf("Greatest common divisor:%d",m);

    return 0;
}
*/

/*程算1作业2.5百分制换为等级制*/
/*
#include<stdio.h>
int main()
{
    int grade,ten;
    printf("Enter numerical grade:");
    scanf("%d",&grade);
    ten=grade/10;

    if (grade<0 || grade>100 )
        printf("Error, grade must be between 0 and 100.");
    else
        if(ten<=5)
        {
            printf("Letter grade: F");
        }
        else
        switch(ten)
        {
            case(10):
                printf("Letter grade:A\n");
                break;
            case(9):
                printf("Letter grade:A\n");
                break;
            case(8):
                printf("Letter grade:B\n");
                break;
            case(7):
                printf("Letter grade:C\n");
                break;
            case(6):
                printf("Letter grade:D\n");
                break;
        }
return 0;
}
*/

/*程算1作业2.6通用产品代码*/
/*
#include <stdio.h>
int main(void)
{
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, last_num,first_sum, second_sum, total,check;
	
	printf("Enter the first (single) digit:");
	scanf("%1d", &d);

	printf("Enter the first group of five digits:");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

	printf("Enter the second group of five digits:");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

    printf("Enter the last (single) digit:");
    scanf("%d",&last_num);
    
	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3*first_sum + second_sum;
	
	check=9-((total-1)%10);
	
    if (check==last_num)
        printf("VALID");
    else
        printf("NOT VALID");

	return 0;
}
*/

/*程算1作业2.7风速等级*/
/*
#include<stdio.h>
int main()
{
    int speed;

    printf("Enter a wind speed:");
    scanf("%d",&speed);

    if (speed<1)
        printf("Calm");
    else if(speed>=1&&speed<=3)
        printf("Light air");
    else if(speed>=4&&speed<=27)
        printf("Breeze");
    else if(speed>=28&&speed<=47)
        printf("Gale");
    else if(speed>=48&&speed<=63)
        printf("Storm");
    else
        printf("Hurricane");

return 0;
}
*/

/*程算1作业2.8 24小时制转12小时制*/
/*
#include<stdio.h>
int main()
{
    int hour_24,minute,hour_12;

    printf("Enter a 24-hour time:");
    scanf("%d:%d",&hour_24,&minute);

    if(hour_24>12)
    {
        hour_12=hour_24-12;
        printf("Equivalent 12-hour time:%02d:%02d PM",hour_12,minute);
    }
    else if(hour_24==12)
    {
        hour_12=hour_24;
        printf("Equivalent 12-hour time:%02d:%02d PM",hour_12,minute);
    }
    else if(hour_24<12&&hour_24>=1)
    {
        hour_12=hour_24;
        printf("Equivalent 12-hour time:%02d:%02d AM",hour_12,minute);
    }
    else
    {
        hour_12=hour_24+12;
        printf("Equivalent 12-hour time:%02d:%02dAM",hour_12,minute);
    }

return 0;
}
*/
