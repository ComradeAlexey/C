#include"TypesData.h"
struct list * Swap(struct list *first, struct list *second, struct list *head)
{

	struct db buf;
	buf = first->_db;
	first->_db = second->_db;
	second->_db = buf;

	return head;
}

int BoolReturnNameUser(struct list *p)
{
	if (p->_db.name_user[0] > p->next->_db.name_user[0])
	{
		return 1;
	}
	else
		return 0;
}

int BoolReturnNameTypePC(struct list *p)
{
	if (p->_db.typePC.nameType[0] > p->next->_db.typePC.nameType[0])
	{
		return 1;
	}
	else
		return 0;
}

int BoolReturnSurnameUser(struct list *p)
{
	if (p->_db.surname_user[0] > p->next->_db.surname_user[0])
	{
		return 1;
	}
	else
		return 0;
}

int BoolReturnGroupeUser(struct list *p)
{
	if (p->_db.groupe_user[0] > p->next->_db.groupe_user[0])
	{
		return 1;
	}
	else
		return 0;
}

int BoolReturnNamePC(struct list *p)
{
	if (p->_db.name_pc[0] > p->next->_db.name_pc[0])
	{
		return 1;
	}
	else
		return 0;
}

struct list * SwapInAscendingSort(struct list *p, struct list *head, int *numSwap, int typeSort)
{
	int resultBool = 0, _numSwap;
	switch (typeSort)
	{
	case 1:
		resultBool = BoolReturnNameUser(p);
		break;
	case 2:
		resultBool = BoolReturnSurnameUser(p);
		break;
	case 3:
		resultBool = BoolReturnGroupeUser(p);
		break;
	case 4:
		resultBool = BoolReturnNamePC(p);
		break;
	case 5:
		resultBool = BoolReturnNameTypePC(p);
		break;
	}
	if (resultBool == 1)
	{
		head = Swap(p, p->next, head);
		_numSwap = *numSwap;
		_numSwap++;
		*numSwap = _numSwap;
	}
	return head;
}

struct list * AscendingSort(struct list *head, int typeSort, int *lenghtLists)
{
	struct list *p = head;
	int index = 0;
	int lL = *lenghtLists;
	if (lL == 1)
	{
		printf("Сортировка не может быть выполнена т.к. в списке всего лишь один элемент!");
	}
	else if (lL == 2)
	{
		if (p->_db.name_user[0] > p->next->_db.name_user[0])
		{
			printf("Сортировка выполнена!");
			head = Swap(p, p->next, head);
		}
	}
	else
	{
		int numSwap = 0;
		do
		{
			numSwap = 0;
			index = 0;
			p = head;
			while (index < lL - 1)
			{
				if (index <= lL - 2)
				{
					head = SwapInAscendingSort(p, head, &numSwap, typeSort);
				}
				p = p->next;
				index++;
			}
		} while (numSwap > 0);
		printf("Сортировка выполнена!");
	}
	return head;
}