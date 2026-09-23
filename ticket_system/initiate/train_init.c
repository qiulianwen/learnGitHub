#include"baseText.h"
#include<stdio.h>

void train_init(ticketList** head)
{
    *head=NULL;
    FILE* fp=fopen("ticketpool.txt","r");
    if(!fp) 
    {
        printf("open ticketpool.txt fail"); 
        return;
    }

    ticketList *newNode,*tail=NULL;

    while (1)
    {
        // 分配节点
        if(!(newNode=malloc(sizeof(ticketList))))
        {
            printf("malloc fail");
            // 释放已分配节点
            ticketList* temp;
            while(*head != NULL)
            {
                temp=*head;
                *head=(*head)->next_ticket_list;
                free(temp);
            }
            *head = NULL; 
            fclose(fp);
            return;
        }

        newNode->next_ticket_list=NULL;

        int n=fscanf(fp,"%hu %4s %19s %19s %hd %hd %hd %hd %hu",
                    &newNode->ticket_info.price,            //1.Price
                    newNode->ticket_info.ID,                //2.ID
                    newNode->ticket_info.startingStation,   //3.Start
                    newNode->ticket_info.lastStation,       //4.End
                    &newNode->ticket_info.ticketTime.month, //5.Month
                    &newNode->ticket_info.ticketTime.day,   //6.Day
                    &newNode->ticket_info.ticketTime.hour,  //7.Hour
                    &newNode->ticket_info.ticketTime.minute,//8.Minute
                    &newNode->ticket_info.ticketNum);       //9.Num

        if(n==9)
        {
            if(!*head) 
                *head=tail=newNode;
            else 
            {
                tail->next_ticket_list=newNode; 
                tail=newNode;
            }
        } 
        else
        { // 读取失败/到末尾
            free(newNode);
            if(n!=EOF)
                printf("format error");
            break;
        }
    }

    fclose(fp);
}
