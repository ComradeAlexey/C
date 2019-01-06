#include"TypesData.h"
void deletelem(struct list *lst,int *lenghtLists) {
	struct list *cur = lst, *prev, *next;
	int a = 0, i = 0;
	do
	{
		printf("\nEnter the element after which you want to delete the element = ");
		scanf_s("%d", &a);
	} while (a == -1);
	if (a > 0)
	{
		while ((i < a) & (cur->next != NULL))
		{
			cur = cur->next;
			i++;
		}
		if (i == a)
		{
			prev = cur->prev; // узел, предшествующий lst
			next = cur->next; // узел, следующий за lst
			if (prev != NULL)
				prev->next = cur->next; // переставляем указатель
			if (next != NULL)
				next->prev = cur->prev; // переставляем указатель
			free(cur); // освобождаем память удаляемого элемента
			*lenghtLists--;
		}
		else
		{
			printf("Not element #%d", a - 1);
		}
	}
	else
	{
		printf("This element == head!!!");
	}
}

void DeleteEndElement(struct list *root, int *lenghtLists)
{
	struct list *cur = root;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	if (cur != root)
	{
		cur->prev->next = NULL;
		free(cur);
		printf("Element deleting!");
		*lenghtLists--;
	}
	else
	{
		printf("This element == head!!!");
	}
}

struct list * deleteHead(struct list *root, int *lenghtLists) {
	struct list *temp;
	if (root->next != NULL)
	{
		temp = root->next;
		free(root);
		printf("Element deleting!");
		*lenghtLists--;
		return temp;
	}
	else
	{
		printf("Only head there is in the list!!!");
		return temp;
	}
}