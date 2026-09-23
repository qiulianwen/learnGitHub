#include"baseText.h"
void free_ticket_list(ticketList** head)
{
    if (head==NULL||*head==NULL)
    {
        return;
    }
    ticketList* cur=*head;
    ticketList* next=NULL;
    while (cur!=NULL)
    {
        next=cur->next_ticket_list;
        free(cur);
        cur=next;
    }
    *head=NULL;
}