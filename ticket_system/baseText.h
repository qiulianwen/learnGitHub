#define MAXIDLEN 5 //车次长度
#define MAXSTALEN 10  //车站名长度
#define MAXUSERIDLEN 20  //用户ID长度
#define MAXPASSWORDLEN 20  //用户密码长度

typedef struct {
    short month;
    short day;
    short hour;
    short minute;
}time;//车次时间（月、日、准确时间）

typedef struct {
    char ID[MAXIDLEN];//车次
    char startingStation[MAXSTALEN];//始发站
    char lastStation[MAXSTALEN];//终点站
    time ticketTime;//车次时间
    unsigned short price;//车票价格
    unsigned short ticketNum;//车票数量
}ticketInfo;

typedef struct ticketList{
    ticketInfo ticket_info;//本车票信息
    struct ticketList* next_ticket_list;//指向下一个车票的地址
}ticketList;

typedef enum {
    ADM=2,//管理员
    USER=3//普通用户
}userType;

typedef struct boughtList{
    char ID[MAXIDLEN];
    unsigned short boughtNum;
    struct boughtList* next_boughtList;
}boughtList;

typedef struct {
    userType user_type;//用户类型
    char userID[MAXUSERIDLEN];//用户名
    char userPassword[MAXPASSWORDLEN];//用户密码
}userInfo;

typedef struct userList{
    userInfo user_info;//本用户信息
    struct userList* next_user_list;//指向下一个用户
}userList;

//version 2.1.3