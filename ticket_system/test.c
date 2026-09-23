#include "baseText.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count_user_list(userList* head) {
    int count = 0;
    userList* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next_user_list;
    }
    return count;
}
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
void print_user_list(userList* head) {
    if (head == NULL) {
        printf("用户列表为空！\n");
        return;
    }

    printf("===== 读取的用户列表（共 %d 个用户）=====\n", count_user_list(head));
    userList* cur = head;
    int idx = 1;
    while (cur != NULL) {
        printf("第%d个用户：\n", idx);
        printf("  类型：%s（枚举值：%d）\n", 
               cur->user_info.user_type == ADM ? "管理员" : "普通用户", 
               cur->user_info.user_type);
        printf("  用户名：%s\n", cur->user_info.userID);
        printf("  密码：%s\n", cur->user_info.userPassword);
        printf("----------------------------------\n");
        cur = cur->next_user_list;
        idx++;
    }
}
void free_user_list(userList* head) {
    userList* temp;
    while (head != NULL) {
        temp = head;
        head = head->next_user_list;
        free(temp);
    }
}

int main() 
{
    // 1. 初始化用户链表头指针
    userList* user_head = NULL;

    // 2. 调用 user_init 读取 userpool.txt
    printf("开始读取 userpool.txt...\n");
    user_init(&user_head);

    // 3. 打印读取结果（验证是否成功）
    print_user_list(user_head);

    // 4. 释放内存（必做，避免内存泄漏）
    free_user_list(user_head);
    printf("\n用户链表内存已释放!\n");

    return 0;
}