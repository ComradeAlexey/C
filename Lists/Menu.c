#include <stdio.h>
#include"TypesData.h"
#include"AddList.h"
#include"DeleteList.h"
#include"EditList.h"
#include"SortList.h"
#include"Print.h"
void Menu(struct list *head,int *lenghtTypesPC, int *lenghtLists,struct TypePC *typesPC)
{
	while (1)
	{
		system("cls");
		if (head == NULL)
		{
			printf("������� ������ ��� �����\n");
			printf("1)�������� �������� �������\n");
			printf("2)�����\n������� ����� = ");
			int choice;
			scanf_s("%d", &choice);
			struct db _db;
			switch (choice)
			{
			case 1:
				_db = dbEnterData(lenghtTypesPC, typesPC);
				head = init(_db, lenghtLists);
				break;
			case 2:
				return;
				break;
			}
		}
		else
		{
			printf("������� ������ ��� �����\n");
			printf("1)�������� ������� ����� ����������\n");
			printf("2)�������� ������� � ����� ������\n");
			printf("3)������������� �������\n");
			printf("4)������� ������� ����� ����������\n");
			printf("5)������� ��������� � ������ �������\n");
			printf("6)������� �������� �������\n");
			printf("7)������� ��� ��������\n");
			printf("8)���������� �� �����\n");
			printf("9)���������� �� �������\n");
			printf("10)���������� �� ������ ������������\n");
			printf("11)���������� �� ���� ��\n");
			printf("12)���������� �� ����� ��\n");
			printf("13)�����\n������� ����� = ");
			int choice;
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:
				addelem(head, lenghtLists, lenghtTypesPC, typesPC);
				break;
			case 2:
				addElemToEnd(head, lenghtTypesPC, typesPC, lenghtLists);
				break;
			case 3:
				EditElement(head, lenghtTypesPC, typesPC, lenghtLists);
				break;
			case 4:
				DeletElemAfter(head,lenghtLists);
				break;
			case 5:
				DeleteEndElement(head, lenghtLists);
				break;
			case 6:
				head = DeleteHead(head, lenghtLists);
				break;
			case 7:
				listPrint(head);
				break;
			case 8:
				head = AscendingSort(head, 1, lenghtLists);
				break;
			case 9:
				head = AscendingSort(head, 2, lenghtLists);
				break;
			case 10:
				head = AscendingSort(head, 3, lenghtLists);
				break;
			case 11:
				head = AscendingSort(head, 5, lenghtLists);
				break;
			case 12:
				head = AscendingSort(head, 4, lenghtLists);
				break;
			case 13:
				return;
				break;
			}
			getchar(); getchar();
		}
	}
}