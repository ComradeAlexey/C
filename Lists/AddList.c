#include"TypesData.h"
#include"ClearTrash.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct list * init(struct db a,int *lenghtLists)  // а - значение первого узла
{
	struct list *lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	//присвоение данных
	lst->_db = a;
	lst->next = NULL; // указатель на следующий узел
	lst->prev = NULL; // указатель на предыдущий узел
	int b = *lenghtLists;
	b++;
	*lenghtLists = b;;
	return(lst);
} 

struct addIP AddPartIP(int numPart)
{
	struct addIP add;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[4];
	printf("Введите %d часть IP = ", numPart);
	scanf_s("%s", &str,4);
	fseek(stdin, 0, SEEK_END);
	for (int i = 0; i < 3; i++)
	{

		if (str[i] == '\0')
		{
			i = 3;
		}
		else if ((str[i] > '9' || str[i] < '0') & (str[i] != '\0'))
		{
			isString = 1;
		}
	}
	if (isString == 0)
	{
		if (str[1] == '\0')
		{
			a += str[0] - '0';
		}
		else if (str[2] == '\0')
		{
			a += ((str[0] - '0') * 10) + (str[1] - '0');
		}
		else
		{
			a += (((str[0] - '0') * 100) + ((str[1] - '0') * 10) + (str[2] - '0'));
		}
	}
	add.a = a;
	add.isString = isString;
	return add;
}

int AddIP(int numPart)
{
	int ip;
	struct addIP add;
	do
	{
		add = AddPartIP(numPart);
	} while (add.a < 0 || add.a > 255 || !add.isString == 0);
	ip = add.a;

	return ip;
}

char* AddString(char *name, int lenghtString)
{
	char *str;
	str = (char *)malloc(lenghtString * sizeof(char));
	printf("Enter %s p.s. only a,b,c... and 1,2,3 other symbols delete! = ", name);
	scanf_s("%s", str, lenghtString+1);
	ClearTrash(str, lenghtString);
	fseek(stdin, 0, SEEK_END);
	return str;
}

struct db dbEnterData(int *lenghtTypesPC, struct  TypePC *typesPC)
{
	struct db _db;
	struct addIP add;
	int lenghtTPC = *lenghtTypesPC;//данные указателя lenghtTypesPC
	//ввод IP
	printf("Enter of IP\n p.s. interval from 0 to 255\n");
	int a = 0, isString = 0, isNull1, isNull2;

	_db._ip.oneCell = AddIP(1);
	_db._ip.twoCell = AddIP(2);
	_db._ip.threeCell = AddIP(3);
	_db._ip.fourCell = AddIP(4);

	_db.name_user = AddString("Name User", 10);
	_db.surname_user = AddString("SurName User", 10);
	_db.name_pc = AddString("Name PC", 10);
	_db.groupe_user = AddString("Groupe user", 5);

	if (lenghtTPC == 0)
	{
		printf("\nВвод первого типа ПК\n");
		typesPC = AddInListTypePC(lenghtTypesPC, typesPC);
		lenghtTPC = *lenghtTypesPC;
		_db.typePC = typesPC[0];
	}
	else
	{
		char choice = '0';
		int b = 0;
		ChoiceYN("Хотите ли Вы добавить новый тип ПК",&choice);
		if (choice == 'y' || choice == 'Y')
		{
			typesPC = AddInListTypePC(lenghtTypesPC, typesPC);
			lenghtTPC = *lenghtTypesPC;
			ChoiceYN("Хотите ли Вы добавить новый тип ПК в качестве типа данного ПК или выбрать другой тип", &choice);
			if (choice == 'y' || choice == 'Y')
			{
				_db.typePC = typesPC[lenghtTPC - 1];
			}
			else
			{
				_db = ChoiceType(lenghtTPC, typesPC, _db);
			}
		}
		else
		{
			_db = ChoiceType(lenghtTPC,typesPC,_db);
		}
	}
	fseek(stdin, 0, SEEK_END);
	return _db;
}

//добавление элемента между элементами
void addelem(struct list *head,int *lenghtLists, int *lenghtTypesPC, struct  TypePC *typesPC) 
{
	struct list *temp, *p, *cur = NULL;
	int i = 0, a = -1;
	fseek(stdin, 0, SEEK_END);
	if (head->next != NULL)
	{
		do
		{
			printf("\nEnter the element after which you want to add the element = ");
			scanf_s("%d", &a);
		} 
		while (a == -1);
		cur = head;
		if (a > 0)
		{
			while ((i < a) & (cur->next != NULL))
			{
				cur = cur->next;
				i++;
			}
		}
		if (cur->next != NULL)
		{
			if (i == a)
			{
				struct db newItem = dbEnterData(lenghtTypesPC, typesPC);
				temp = (struct list*)malloc(sizeof(struct list));
				p = cur->next; // сохранение указателя на следующий узел
				cur->next = temp; // предыдущий узел указывает на создаваемый
				temp->_db = newItem; // сохранение поля данных добавляемого узла
				temp->next = p; // созданный узел указывает на следующий узел
				temp->prev = cur; // созданный узел указывает на предыдущий узел
				if (p != NULL)
					p->prev = temp;
				*lenghtLists++;
			}
			else
			{
				printf("Not element #%d", a - 1);
			}
		}
		else
		{
			printf("Not element #%d", a - 1);
		}
	}
	else 
	{
		printf("This element == head!!! & head->next = NULL!!!!");
	}
}

//добавление элемента в конец списка
void addElemToEnd(struct list *head, int *lenghtTypesPC, struct  TypePC *typesPC,int *lenghtLists) 
{
	struct list *temp, *cur;
	cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	struct db newItem = dbEnterData(lenghtTypesPC, typesPC);
	temp = (struct list*)malloc(sizeof(struct list));
	cur->next = temp; // предыдущий узел указывает на создаваемый
	temp->_db = newItem; // сохранение поля данных добавляемого узла
	temp->prev = cur; // созданный узел указывает на предыдущий узел
	temp->next = NULL;
	int b = *lenghtLists;
	b++;
	*lenghtLists = b;;
}