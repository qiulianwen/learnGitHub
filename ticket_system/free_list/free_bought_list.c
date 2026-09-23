#include"baseText.h"
void free_bought_list(boughtList** head)
{
    if (head==NULL||*head==NULL)
    {
        return;
    }
    boughtList* cur=*head;
    boughtList* next=NULL;
    while (cur!=NULL)
    {
        next=cur->next_boughtList;
        free(cur);
        cur=next;
    }
    *head=NULL;
}