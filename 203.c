/* 203. Remove Linked List Elements */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* pnow;
    struct ListNode* ptr;
    if(head != NULL) pnow = head;
    else pnow = NULL;
    while(pnow != NULL && pnow->val == val)
    {
        pnow = pnow->next;
    }
    head = pnow;
    ptr = pnow;
    if(pnow != NULL) pnow = pnow->next;
    else pnow = NULL;
    while(pnow != NULL)
    {
        if(pnow->val == val)
        {
            ptr->next = pnow->next;
        }
        else
        {
            ptr = ptr->next;
        }
        pnow = pnow->next;
    }
    return head;
}
