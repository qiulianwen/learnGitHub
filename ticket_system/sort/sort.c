//类型enum（汽车，火车），发车时间、到站时间，票价，始发站、终点站，剩余数量
//管理员权限：票数管理、增删、时间修改、票价修改
//用户权限：搜索（按照发车时间(short)、到站时间，票价(short)，始发站(string)、终点站）
//         排序（时间、票价、是否有票）
//         购买
//负责模块：**排序**

//排序（时间、票价、是否有票:没票放后面）
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXIDLEN 4 //车次长度
#define MAXSTALEN 10  //车站名长度
#define MAXUSERIDLEN 20  //用户ID长度
#define MAXPASSWORDLEN 20  //用户密码长度

typedef enum {
    ADM=2,//管理员
    USER=3//普通用户
}userType;

typedef struct {
    userType user_type;//用户类型
    char userID[MAXUSERIDLEN];//用户名
    char userPassword[MAXPASSWORDLEN];//用户密码
}userInfo;

typedef struct userList{
    userInfo user_info;//本用户信息
    struct userList* next_user_list;//指向下一个用户
}userList;

typedef enum {
    BUS=0,
    TRAIN=1
}ticketType;//车辆类型

typedef struct {
    short month;
    short day;
    short hour;
    short minute;
}Time;//车次时间（月、日、准确时间）

typedef struct {
    ticketType type;//车辆类型
    short price;//车票价格
    char ID[MAXIDLEN];//车次（如K1234）
    char startingStation[MAXSTALEN];//始发站
    char lastStation[MAXSTALEN];//终点站
    Time ticketTime;//车次时间
    short ticketNum;//车票数量
}ticketInfo;

typedef struct ticketList{
    ticketInfo ticket_info;//本车票信息
    struct ticketList* next_ticket_list;//指向下一个车票的地址
}ticketList;



void price_sort(ticketList* head)
{
//按票价从小到大
    int ticket_count = 0;
    ticketList* cur = head;
    while (cur != NULL) 
    {
        ticket_count++;
        cur=cur->next_ticket_list;
    }
    
    for (int i=0;i<ticket_count-1;i++)
    {
        cur=head;
        for (int j=0;j<ticket_count-1-i;j++) 
        {
            if (head->ticket_info.price>head->ticket_info.price)
            {
                ticketInfo temp = cur->ticket_info;
                cur->ticket_info = cur->next_ticket_list->ticket_info;
                cur->next_ticket_list->ticket_info = temp;
            }
        cur=cur->next_ticket_list;  
        }
    }
}


void time_sort(ticketList* head)
{
//按时间从小到大
    int ticket_count = 0;
    ticketList* cur = head;
    while (cur != NULL) 
    {
        ticket_count++;
        cur=cur->next_ticket_list;
    }

    for (int i=0;i<ticket_count-1;i++) 
    {
        cur=head;
        for (int j=0;j<ticket_count-1-i;j++) 
        {
            Time t1 = head->ticket_info.ticketTime;
            Time t2 = head->next_ticket_list->ticket_info.ticketTime;
            short need_swap = 0;
            if (t1.month > t2.month) 
                need_swap = 1;
            else if (t1.month==t2.month&&t1.day>t2.day) 
                need_swap = 1;
            else if (t1.month==t2.month&&t1.day==t2.day&&t1.hour>t2.hour) 
                need_swap = 1;
            else if (t1.month==t2.month&&t1.day==t2.day&&t1.hour==t2.hour&&t1.minute>t2.minute) 
                need_swap = 1;
            head=head->next_ticket_list;

            if (need_swap)
            {
                ticketInfo temp = cur->ticket_info;
                cur->ticket_info = cur->next_ticket_list->ticket_info;
                cur->next_ticket_list->ticket_info = temp;
            }
        cur=cur->next_ticket_list;           
        }
    }
}  