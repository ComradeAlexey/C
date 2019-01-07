#include"TypesData.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct list * init(struct db a,int *lenghtLists)  // � - �������� ������� ����
{
	struct list *lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	//���������� ������
	lst->_db = a;
	lst->next = NULL; // ��������� �� ��������� ����
	lst->prev = NULL; // ��������� �� ���������� ����
	int b = *lenghtLists;
	b++;
	*lenghtLists = b;;
	return(lst);
} 

struct TypePC *AddInListTypePC(int *lenghtTypesPC, struct TypePC *typesPC)
{
	int i = *lenghtTypesPC;
	i++;
	typesPC = (struct  TypePC*)realloc(typesPC, i * sizeof(struct TypePC));
	printf("������� �������� ���� �� = ");
	typesPC[i-1].typeNum = i;
	scanf_s("%s", typesPC[i - 1].nameType, 10);
	*lenghtTypesPC = i;
	return typesPC;
}

struct addIP AddPartIP(int numPart)
{
	struct addIP add;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[4];
	printf("������� %d ����� IP = ", numPart);
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
	scanf_s("%s", str, lenghtString);
	ClearTrash(str, lenghtString);
	fseek(stdin, 0, SEEK_END);
	return str;
}

void ChoiceYN(char *str, char *choice)
{
	int b;
	do
	{
		printf("\n%s? ���� �� �� ������� Y(y), ����� N(n) = ",str);
		scanf_s("%c", choice);
		fseek(stdin, 0, SEEK_END);
		switch (*choice)
		{
		case 'N':
			b = 1;
			break;
		case 'n':
			b = 1;
			break;
		case 'y':
			b = 1;
			break;
		case 'Y':
			b = 1;
			break;
		default:
			b = 0;
			break;
		}
	} while (b == 0);
}
struct db ChoiceType(int lenghtTPC, struct TypePC *typesPC, struct db _db)
{
	int choIce = -1;
	printf("\n�������� ��� �� �� ������ � ������� ���������� ����� ���� �����:");
	for (int i = 0; i < lenghtTPC; i++)
	{
		printf("\n%d) %s", i, typesPC[i]);
	}
	do
	{
		printf("\n������� ���������� ����� �� 0 �� %d = ", lenghtTPC - 1);
		scanf_s("%d", &choIce);
	} while (choIce < 0 || choIce >= lenghtTPC);
	_db.typePC = typesPC[choIce];
	return _db;
}
struct db dbEnterData(int *lenghtTypesPC, struct  TypePC *typesPC)
{
	struct db _db;
	struct addIP add;
	int lenghtTPC = *lenghtTypesPC;//������ ��������� lenghtTypesPC
	//���� IP
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
		printf("\n���� ������� ���� ��\n");
		typesPC = AddInListTypePC(lenghtTypesPC, typesPC);
		lenghtTPC = *lenghtTypesPC;
		_db.typePC = typesPC[0];
	}
	else
	{
		char choice = '0';
		int b = 0;
		ChoiceYN("������ �� �� �������� ����� ��� ��",&choice);
		if (choice == 'y' || choice == 'Y')
		{
			AddInListTypePC(lenghtTypesPC, typesPC);
			lenghtTPC = *lenghtTypesPC;
			ChoiceYN("������ �� �� �������� ����� ��� �� � �������� ���� ������� �� ��� ������� ������ ���", &choice);
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

//���������� �������� ����� ����������
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
				p = cur->next; // ���������� ��������� �� ��������� ����
				cur->next = temp; // ���������� ���� ��������� �� �����������
				temp->_db = newItem; // ���������� ���� ������ ������������ ����
				temp->next = p; // ��������� ���� ��������� �� ��������� ����
				temp->prev = cur; // ��������� ���� ��������� �� ���������� ����
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

//���������� �������� � ����� ������
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
	cur->next = temp; // ���������� ���� ��������� �� �����������
	temp->_db = newItem; // ���������� ���� ������ ������������ ����
	temp->prev = cur; // ��������� ���� ��������� �� ���������� ����
	temp->next = NULL;
	int b = *lenghtLists;
	b++;
	*lenghtLists = b;;
}