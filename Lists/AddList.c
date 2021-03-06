#include"TypesData.h"
#include"ClearTrash.h"
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

struct DBAndTPC dbEnterData(int *lenghtTypesPC, struct TypePC *typesPC)
{
	struct db _db;
	struct DBAndTPC _DBAndTPC;
	int lenghtTPC = *lenghtTypesPC;//������ ��������� lenghtTypesPC
	//���� IP
	printf("Enter of IP\n p.s. interval from 0 to 255\n");
	int a = 0, isString = 0;

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
		choice = ChoiceYN("������ �� �� �������� ����� ��� ��");
		if (choice == 'y' || choice == 'Y')
		{
			typesPC = AddInListTypePC(lenghtTypesPC, typesPC);
			lenghtTPC = *lenghtTypesPC;
			choice = ChoiceYN("������ �� �� �������� ����� ��� �� � �������� ���� ������� �� ��� ������� ������ ���");
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
	_DBAndTPC.typePC = typesPC;
	_DBAndTPC._db = _db;
	return _DBAndTPC;
}

//���������� �������� ����� ����������
struct ListAndTypePC addelem(struct list *head,int *lenghtLists, int *lenghtTypesPC, struct  TypePC *typesPC)
{
	struct ListAndTypePC LATPC;
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
				struct DBAndTPC _DBAndTPC;
				struct db newItem; 
				_DBAndTPC = dbEnterData(lenghtTypesPC, typesPC);
				typesPC = _DBAndTPC.typePC;
				newItem = _DBAndTPC._db;
				temp = (struct list*)malloc(sizeof(struct list));
				p = cur->next; // ���������� ��������� �� ��������� ����
				cur->next = temp; // ���������� ���� ��������� �� �����������
				temp->_db = newItem; // ���������� ���� ������ ������������ ����
				temp->next = p; // ��������� ���� ��������� �� ��������� ����
				temp->prev = cur; // ��������� ���� ��������� �� ���������� ����
				if (p != NULL)
					p->prev = temp;
				int lL = *lenghtLists;
				lL++;
				*lenghtLists = lL; 
				LATPC.list = head;
				LATPC.typePC = typesPC;
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
	
	return LATPC;
}

//���������� �������� � ����� ������
struct ListAndTypePC addElemToEnd(struct list *head, int *lenghtTypesPC, struct  TypePC *typesPC,int *lenghtLists)
{
	struct ListAndTypePC LATPC;
	struct list *temp, *cur;
	cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	struct DBAndTPC _DBAndTPC;
	struct db newItem;
	_DBAndTPC = dbEnterData(lenghtTypesPC, typesPC);
	typesPC = _DBAndTPC.typePC;
	newItem = _DBAndTPC._db;
	temp = (struct list*)malloc(sizeof(struct list));
	cur->next = temp; // ���������� ���� ��������� �� �����������
	temp->_db = newItem; // ���������� ���� ������ ������������ ����
	temp->prev = cur; // ��������� ���� ��������� �� ���������� ����
	temp->next = NULL;
	int b = *lenghtLists;
	b++;
	*lenghtLists = b;
	LATPC.list = head;
	LATPC.typePC = typesPC;
	return LATPC;
}