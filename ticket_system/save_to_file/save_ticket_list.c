#include"baseText.h"
void save_ticket_list(ticketList* head)
{
    FILE* fp=fopen("ticketpool.txt", "w");

    if (fp==NULL)
    {
        // 输出具体错误原因（如权限、磁盘）
        return;
    }
    // 遍历链表，按格式逐行写入
    ticketList* cur = head;
    while (cur != NULL)
    {
        ticketInfo* info = &cur->ticket_info;
        // 格式：价格 车次 始发站 终点站 月 日 时 分 剩余票数
        int ret = fprintf(fp, "%d %s %s %s %d %d %d %d %d\n",
                          info->price,        // 价格
                          info->ID,           // 车次
                          info->startingStation, // 始发站
                          info->lastStation,  // 终点站
                          info->ticketTime.month,  // 月
                          info->ticketTime.day,    // 日
                          info->ticketTime.hour,   // 时
                          info->ticketTime.minute, // 分
                          info->ticketNum);    // 剩余票数

        cur = cur->next_ticket_list;
    }

    fclose(fp);
}