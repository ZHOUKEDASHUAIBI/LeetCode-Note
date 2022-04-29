struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* pnow;
    struct ListNode* prev = head;
    if(head != NULL) pnow = head->next;
    else pnow = NULL;
    while(pnow != NULL)
    {
        while(pnow != NULL && pnow->val == prev->val)
        {
            pnow = pnow->next;
        }
        prev->next = pnow;
        prev = pnow;
    }
    return head;
}
