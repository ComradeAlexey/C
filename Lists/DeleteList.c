#include"TypesData.h"
#include "DeleteList.h"
void DeletElemAfter(struct list *lst,int *lenghtLists) {
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
			int b;
			b = *lenghtLists;
			b--;
			*lenghtLists = b;
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
		int b;
		b = *lenghtLists;
		b--;
		*lenghtLists = b;
	}
	else
	{
		printf("This element == head!!!");
	}
}

struct list * DeleteHead(struct list *root, int *lenghtLists) {
	struct list *temp;
	if (root->next != NULL)
	{
		temp = root->next;
		free(root);
		printf("Element deleting!");
		int b;
		b = *lenghtLists;
		b--;
		*lenghtLists = b;
		return temp;
	}
	else
	{
		printf("Only head there is in the list!!!");
		return root;
	}
}

/*struct TypePC **/void DeleteAllTypesPC(struct TypePC *tpc, int *lenghtTypesPC)
{
	free(tpc);
	int lTPC = *lenghtTypesPC;
	lTPC = 0;
	*lenghtTypesPC = lTPC;
	//return tpc;
}

struct list * DeleteTypePC(struct list *head, struct TypePC *typesPC, int * lenghtTypesPC, int *lenghtLists)
{
	struct list *select = head;
	int lTPC = *lenghtTypesPC;
	printf("\nEnter number type PC: ");
	for (int i = 0; i < lTPC; i++)
	{
		printf("\n%d)%s", i, typesPC[i].nameType);
	}
	int numSelected = -1;
	do
	{
		printf("\nEnter number type PC for delete= ");
		scanf_s("%d", &numSelected);
	} while ((numSelected < 0) || (numSelected > lTPC));

	for (int i = 0; i < 10; i++)
	{
		typesPC[numSelected].nameType[i] = typesPC[lTPC-1].nameType[i];
	}
	int lenLists = *lenghtLists;
	for (int i = 0; i < lenLists; i++)
	{
		if (select->_db.typePC.typeNum-1 == numSelected)
		{
			for (int j = 0; j < 10; j++)
			{
				select->_db.typePC.nameType[j] = typesPC[numSelected].nameType[j];
			}
		}
		select = select->next;
	}
	lTPC--;
	typesPC = (struct TypePC*)realloc(typesPC, lTPC * sizeof(struct TypePC));
	*lenghtTypesPC = lTPC;
	return head;
}
