#include"baseText.h"
#include<stdio.h>

void user_init(userList** head)
{
    *head = NULL;
    FILE* fp = fopen("userpool.txt", "r");
    if (!fp)
    { 
        printf("open userpool.txt fail");
        return;
    }

    userList *newNode,*tail=NULL;
    while (1)
    {
        //1.分配节点
        newNode=malloc(sizeof(userList));
        if (!newNode)
        {
            printf("malloc user fail");
            // 释放已分配节点
            userList* temp;
            while (*head != NULL)
            {
                temp=*head;
                *head = (*head)->next_user_list;
                free(temp);
            }
            *head=NULL;
            fclose(fp);
            return;
        }
        newNode->next_user_list=NULL;

        //2.读取到节点字段
        //type变量是枚举转换必需
        int type;
        int readCnt = fscanf(fp,"%d %19s %19s", 
                            &type,
                            newNode->user_info.userID,        //写入用户ID
                            newNode->user_info.userPassword); //写入密码

        //3.校验并处理读取结果
        if(readCnt==3)
        {
            //赋值到节点
            newNode->user_info.user_type=(userType)type;
            //尾插链表
            if(!*head)
                *head=tail=newNode; 
            else
            {
                tail->next_user_list=newNode;
                tail=newNode;
            }
        } 
        else
        {
            // 读取失败，释放当前空节点
            free(newNode);
            if (readCnt!=EOF)
            {
                printf("user format error");
            }
            break;
        }
    }

    fclose(fp);
}