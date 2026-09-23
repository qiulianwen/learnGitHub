#include"baseText.h"
#include<stdio.h>

void bought_init(boughtList** head,char* targetUserID)
{
    *head=NULL;
    FILE* fp=fopen("boughtpool.txt","r");

    if(!fp)
    {
        printf("open boughtpool.txt fail");
        return;
    }

    boughtList *newNode,*tail=NULL;
    char readUserID[MAXUSERIDLEN]; // 临时存储读取的用户名

    while (1) {
        // 1. 分配节点
        newNode = (boughtList*)malloc(sizeof(boughtList));
        if (!newNode) {
            printf("malloc bought fail\n");
            // 释放已分配节点
            boughtList* temp;
            while (*head != NULL) {
                temp = *head;
                *head = (*head)->next_boughtList;
                free(temp);
            }
            *head = NULL;
            fclose(fp);
            return;
        }
        newNode->next_boughtList = NULL;

        // 2. 读取数据：先读用户名，再读车次+购买数量
        // 格式：用户名 车次 购买数量（例如：zhangsan G101 2）
        int n = fscanf(fp, "%19s %4s %hu",
                    readUserID,          // 读取当前行的用户名
                    newNode->ID,         // 读取车次ID
                    &newNode->boughtNum);// 读取购买数量

        // 3. 校验读取结果
        if (n == 3) {
            // 3.1 检查是否是目标用户：不是则终止读取
            if (strcmp(readUserID, targetUserID) != 0) {
                free(newNode); // 释放当前节点
                printf("检测到其他用户名<%s>，终止读取\n", readUserID);
                break;
            }

            // 3.2 是目标用户：复制用户名到节点，尾插链表
            if (!*head) 
            { // 链表为空，头节点和尾节点指向新节点
                *head = tail = newNode;
            } else 
            { // 链表非空，尾节点后插
                tail->next_boughtList = newNode;
                tail = newNode;
            }
        } else {
            // 3.3 读取失败（字段数不对/文件尾）：释放节点并终止
            free(newNode);
            if (n != EOF) {
                printf("boughtpool.txt format err (read %d fields)\n", n);
            }
            break;
        }
    }

    fclose(fp);
}