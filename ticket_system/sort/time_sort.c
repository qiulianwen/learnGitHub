void time_sort(ticketList* head)
{
//按时间从小到大
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
            time t1 = head->ticket_info.ticketTime;
            time t2 = head->next_ticket_list->ticket_info.ticketTime;
            short need_swap = 0;
            if (t1.month > t2.month) 
                need_swap = 1;
            else if (t1.month==t2.month&&t1.day>t2.day) 
                need_swap = 1;
            else if (t1.month==t2.month&&t1.day==t2.day&&t1.hour>t2.hour) 
                need_swap = 1;
            else if (t1.month==t2.month&&t1.day==t2.day&&t1.hour==t2.hour&&t1.minute>t2.minute) 
                need_swap = 1;
            head=head->next_ticket_list;

            if (need_swap)
            {
                ticketInfo temp = cur->ticket_info;
                cur->ticket_info = cur->next_ticket_list->ticket_info;
                cur->next_ticket_list->ticket_info = temp;
            }
        cur=cur->next_ticket_list;           
        }
    }
}