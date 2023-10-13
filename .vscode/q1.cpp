bool checkcircular(node* list)
{
    node* head = list;
    while(list->next != NULL)
    {
        if(list->next == head)
        {
            return true;
            break;
        }
    }
    return false;
}
// 1->2->3->4->5->1