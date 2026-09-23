void price_sort(ticketList* head)
{
//按票价从小到大
    int ticket_count = 0;
    ticketList* cur = head;
    while (cur != NULL) 
    {
        ticket_count++;
        cur=cur->next_ticket_list;
    }
    
    for (int i=0;i<ticket_count-1;i++)
    {
        cur=head;
        for (int j=0;j<ticket_count-1-i;j++) 
        {
            if (head->ticket_info.price>head->ticket_info.price)
            {
                ticketInfo temp = cur->ticket_info;
                cur->ticket_info = cur->next_ticket_list->ticket_info;
                cur->next_ticket_list->ticket_info = temp;
            }
        cur=cur->next_ticket_list;  
        }
    }
}