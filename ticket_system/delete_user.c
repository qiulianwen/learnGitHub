#include"baseText.h"
void delete_user(userList** head)
{
 char delUserID[MAXUSERIDLEN];
    printf("请输入要删除的用户ID:");
    scanf("%s",delUserID);

    userList *cur=*head;   // 当前节点
    userList *prev=NULL;   //前驱节点

    //遍历链表查找目标用户
    while(cur!=NULL)
    {
        //匹配目标用户ID
        if (strcmp(cur->user_info.userID, delUserID)==0)
        {
            //处理头节点删除
            if(prev==NULL)
                *head=cur->next_user_list;
            //处理中间/尾节点删除
            else
                prev->next_user_list=cur->next_user_list;

            //释放当前节点内存
            free(cur);
            printf("成功删除用户【%s】\n",delUserID);
            return;
        }
        prev=cur;
        cur=cur->next_user_list;
    }
}