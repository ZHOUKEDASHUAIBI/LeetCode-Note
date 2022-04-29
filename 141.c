/* using two pointers, one goes two nodes per time and the other goes one nodes
   per time. To judge whether there exists cycle or not, we can simply judge that
   whether the two pointers will come across or the faster one will reach NULL*/

bool hasCycle(struct ListNode *head) {
    struct ListNode* pslow;
    struct ListNode* pfast;
    if(head == NULL || head->next == NULL) return false;
    else
    {
        pslow = head->next;
        pfast = head->next->next;
    }
    while(!((pfast == NULL || pfast->next == NULL) || pfast == pslow))
    {
        pfast = pfast->next->next;
        pslow = pslow->next;
    }
    if(pfast == NULL) return false;
    else if(pfast == pslow) return true;
    return 0;
}
