#include"baseText.h"
void free_user_list(userList** head)
{
    if (head==NULL||*head==NULL)
    {
        return;
    }
    userList* cur=*head;
    userList* next=NULL;
    while (cur!=NULL)
    {
        next=cur->next_user_list;
        free(cur);
        cur=next;
    }
    *head=NULL;
}