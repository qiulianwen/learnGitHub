#include"baseText.h"
void save_bought_list(boughtList* head)
{
    FILE* fp=fopen("boughtpool.txt", "w");

    if (fp==NULL)
    {
        return;
    }
    // 遍历链表写入购票记录
    boughtList* cur = head;
    while (cur != NULL)
    {
        // 格式：车次 购票数量
        fprintf(fp, "%s %d\n",
                cur->ID,
                cur->boughtNum);

        cur = cur->next_boughtList;
    }

    fclose(fp);
}