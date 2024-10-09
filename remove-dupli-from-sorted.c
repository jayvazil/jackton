#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode dummy;
	dummy.next = head;
	struct ListNode *prev = &dummy;

	while (head)
	{
		if (head->next && head->val == head->next->val)
		{
			while (head->next && head->val == head->next->val)
			{
				head = head->next;
			}
			prev->next = head->next;
		}
		else
		{
			prev = prev->next;
		}
		head = head->next;
	}

	return dummy.next;
}
struct ListNode* createNode(int val)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void printList(struct ListNode* head)
{
	while (head)
	{
		printf("%d -> ", head->val);
		head = head->next;
	}
	printf("NULL\n");
}

int main()
{
	struct ListNode* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(3);
	head->next->next->next->next = createNode(4);
	head->next->next->next->next->next = createNode(4);
	head->next->next->next->next->next->next = createNode(5);

	printf("Original list: ");
	printList(head);

	struct ListNode* newHead = deleteDuplicates(head);

	printf("List after removing duplicates: ");
	printList(newHead);

	return 0;
}
