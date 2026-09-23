#include"baseText.h"
void save_user_list(userList* head)
{
    FILE* fp=fopen("userpool.txt", "w");

    if (fp==NULL)
    {
        return;
    }
    // 遍历链表写入用户数据
    userList* cur = head;
    while (cur != NULL)
    {
        userInfo* info = &cur->user_info;
        // 格式：用户类型(ADM/USER) 用户名 密码
        const char* type_str = (info->user_type == ADM) ? "ADM" : "USER";
        fprintf(fp, "%s %s %s\n",
                type_str,
                info->userID,
                info->userPassword);

        cur = cur->next_user_list;
    }

    fclose(fp);
}