/* Add Two NUmbers */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	struct ListNode* ptr = head;
	int sum, val = 0;
	while(p1 != NULL && p2 != NULL)
	{
		struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum = p1->val + p2->val + val;
		tmp->val = sum % 10;
		ptr->next = tmp;
		ptr = ptr->next;
		val = sum / 10;
		p1 = p1->next;
		p2 = p2->next;
	}
	while(p1 != NULL)
	{
		struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum = p1->val + val;
		tmp->val = sum % 10;
		ptr->next = tmp;
		ptr = ptr->next;
		val = sum / 10;
		p1 = p1->next;
	}
	while(p2 != NULL)
	{
		struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		sum = p2->val + val;
		tmp->val = sum % 10;
		ptr->next = tmp;
		ptr = ptr->next;
		val = sum / 10;
		p2 = p2->next;
	}
	if(val != 0)
	{
		struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		tmp->val = val;
		ptr->next = tmp;
		ptr = ptr->next;
	}
	ptr->next = NULL;
    head = head->next;
	return head;
}
