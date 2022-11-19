#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node 
	{
		int  value;
		struct Node* next;
	};

void nodelink(struct Node** ref_head, struct Node* a,struct Node* b, struct Node* prevb)
{
	*ref_head = b;
	prevb->next = a;
	struct Node* temp = b->next;
	b->next = a->next;
	a->next = temp;
}

struct Node* recursion(struct Node* head)
{
	if (head->next == NULL)
		return head;
	struct Node* min = head;
	struct Node* prevmin = NULL;
	struct Node* ptr;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next) 
	{

		if (ptr->next->value < min->value) 
		{
			min = ptr->next;
			prevmin = ptr;
		}
	}
	if (min != head)
		nodelink(&head, head, min, prevmin);
		head->next = recursion(head->next);
		return head;
}
void sort(struct Node** ref_head)
{
	if ((*ref_head) == NULL) return;
	*ref_head = recursion(*ref_head);
}
void Insert(struct Node** ref_head, int new_value)
{
	struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
	new_node->value = new_value;
	new_node->next = (*ref_head);
	(*ref_head) = new_node;
}
void display(struct Node* head)
{
	while (head != NULL) 
	{
		cout << head->value << " ";
		head = head->next;
	}
}
int main()
{
	struct Node* head = NULL;

	Insert(&head, 1);
	Insert(&head, 65);
	Insert(&head, 28);
	Insert(&head, 12);
	Insert(&head, 34);
	Insert(&head, 64);
	Insert(&head, 13);
	Insert(&head, 32);
	Insert(&head, 12);
	Insert(&head, 43);
	Insert(&head, 57);
	Insert(&head, 48);
	Insert(&head, 20);
	Insert(&head, 14);
	Insert(&head, 5);

	cout << "Before Sorting : " << endl ;
	display(head);
	sort(&head);
	cout << "\nAfter sorting : " << endl ;
	display(head);

	return 0;
}

